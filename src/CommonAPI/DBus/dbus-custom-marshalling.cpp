
#define DBUS_COMPILATION
#define DBUS_CAN_USE_DBUS_STRING_PRIVATE

extern "C" {

#include <config.h>
#include "dbus/dbus-internals.h"
#include "dbus/dbus-marshal-recursive.h"
#include "dbus/dbus-marshal-validate.h"
#include "dbus/dbus-marshal-byteswap.h"
#include "dbus/dbus-marshal-header.h"
#include "dbus/dbus-signature.h"
#include "dbus/dbus-message-private.h"
#include "dbus/dbus-object-tree.h"
#include "dbus/dbus-string-private.h"
#include "dbus/dbus-memory.h"
#include "dbus/dbus-list.h"
#include "dbus/dbus-threads-internal.h"
#ifdef HAVE_UNIX_FD_PASSING
#include "dbus/dbus-sysdeps.h"
#include "dbus/dbus-sysdeps-unix.h"
#endif

#include "assert.h"
}

//////////////////////////////////////////////////////////////////////////
// The functions defined below should actually be provided by "libdbus-1.so", but they seem not to be exported by it, which is why
// we link against the static library instead


/**
 * Internals of _dbus_assert(); it's a function
 * rather than a macro with the inline code so
 * that the assertion failure blocks don't show up
 * in test suite coverage, and to shrink code size.
 *
 * @param condition TRUE if assertion succeeded
 * @param condition_text condition as a string
 * @param file file the assertion is in
 * @param line line the assertion is in
 * @param func function the assertion is in
 */
void
_dbus_real_assert (dbus_bool_t  condition,
                   const char  *condition_text,
                   const char  *file,
                   int          line,
                   const char  *func)
{
  if (_DBUS_UNLIKELY (!condition))
    {
      _dbus_warn ("%lu: assertion failed \"%s\" file \"%s\" line %d function %s\n",
                  _dbus_pid_for_log (), condition_text, file, line, func);
      _dbus_abort ();
    }
}


/**
 * Gets the raw character buffer from the string.  The returned buffer
 * will be nul-terminated, but note that strings may contain binary
 * data so there may be extra nul characters prior to the termination.
 * This function should be little-used, extend DBusString or add
 * stuff to dbus-sysdeps.c instead. It's an error to use this
 * function on a const string.
 *
 * @param str the string
 * @returns the data
 */
char*
_dbus_string_get_data (DBusString *str)
{
  DBUS_STRING_PREAMBLE (str);

  return (char*) real->str;
}


/**
 * Gets the length of a string (not including nul termination).
 *
 * @returns the length.
 */
int
_dbus_string_get_length (const DBusString  *str)
{
  DBUS_CONST_STRING_PREAMBLE (str);

  return real->len;
}


static dbus_bool_t
set_or_delete_string_field (DBusMessage *message,
                            int          field,
                            int          typecode,
                            const char  *value)
{
  if (value == NULL)
    return _dbus_header_delete_field (&message->header, field);
  else
    return _dbus_header_set_field_basic (&message->header,
                                         field,
                                         typecode,
                                         &value);
}

/* Only have the function if we don't have the macro */
#ifndef _dbus_string_get_allocated
/**
 * Gets the allocated length of a string (not including nul termination).
 *
 * @returns the allocated length.
 */
int
_dbus_string_get_allocated(const DBusString  *str)
{
  DBUS_CONST_STRING_PREAMBLE (str);

  return real->allocated;
}
#endif /* !_dbus_string_get_allocated */

/////////////////////////////////////////////////////////////////////////////
// Below are the actual additional functions needed for the custom marshalling

/*
 * Sets the signature of the message, i.e. the arguments in the
 * message payload. The signature includes only "in" arguments for
 * #DBUS_MESSAGE_TYPE_METHOD_CALL and only "out" arguments for
 * #DBUS_MESSAGE_TYPE_METHOD_RETURN, so is slightly different from
 * what you might expect (it does not include the signature of the
 * entire C++-style method).
 *
 * The signature is a string made up of type codes such as
 * #DBUS_TYPE_INT32. The string is terminated with nul (nul is also
 * the value of #DBUS_TYPE_INVALID). The macros such as
 * #DBUS_TYPE_INT32 evaluate to integers; to assemble a signature you
 * may find it useful to use the string forms, such as
 * #DBUS_TYPE_INT32_AS_STRING.
 *
 * An "unset" or #NULL signature is considered the same as an empty
 * signature. In fact dbus_message_get_signature() will never return
 * #NULL.
 *
 * @param message the message
 * @param signature the type signature or #NULL to unset
 * @returns #FALSE if no memory
 */
dbus_bool_t
dbus_message_set_signature (DBusMessage *message,
                            const char  *signature)
{
  _dbus_return_val_if_fail (message != NULL, FALSE);
  _dbus_return_val_if_fail (!message->locked, FALSE);
  _dbus_return_val_if_fail (signature == NULL || _dbus_check_is_valid_signature (signature), FALSE);
  /* can't delete the signature if you have a message body */
  _dbus_return_val_if_fail (_dbus_string_get_length (&message->body) == 0 ||
                            signature != NULL, FALSE);

  return set_or_delete_string_field (message,
                                     DBUS_HEADER_FIELD_SIGNATURE,
                                     DBUS_TYPE_SIGNATURE,
                                     signature);
}

/*
 * Returns pointer to the buffer used to store the message body.
 *
 * @param message the message
 * @return pointer to the message body memory
 */
char*
dbus_message_get_body (DBusMessage *message) {
  _dbus_return_val_if_fail (message != NULL, NULL);

  return _dbus_string_get_data(&(message->body));
}

/**
 * Adjust the length of the message body buffer. The memory will be reallocated
 * if the new length is bigger than the already allocated size.
 *
 * @see dbus_message_get_body_allocated
 * @param message the message
 * @param length the new length of the body
 * @return #TRUE if successful
 */
dbus_bool_t
dbus_message_set_body_length (DBusMessage *message,
                              int length) {
  _dbus_return_val_if_fail (message != NULL, FALSE);
  _dbus_return_val_if_fail (length >= 0, FALSE);

  return _dbus_string_set_length(&(message->body), length);
}

/**
 * Gets the length of the message body buffer.
 *
 * @param message the message
 * @param length the new length of the body
 * @return the length of the body buffer
 */
int
dbus_message_get_body_length (DBusMessage *message) {
  _dbus_return_val_if_fail (message != NULL, 0);

  return _dbus_string_get_length(&(message->body));
}

/**
 * Gets the allocated memory size used to hold the message body.
 *
 * @param message the message
 * @return size of the allocated message body memory
 */
int
dbus_message_get_body_allocated (DBusMessage *message) {
  _dbus_return_val_if_fail (message != NULL, 0);

  return _dbus_string_get_allocated(&(message->body));
}



