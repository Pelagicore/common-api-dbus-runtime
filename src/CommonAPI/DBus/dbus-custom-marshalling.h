#pragma once

#include <dbus/dbus.h>

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
dbus_bool_t dbus_message_set_signature (DBusMessage *message, const char *signature);

/*
 * Returns pointer to the buffer used to store the message body.
 *
 * @param message the message
 * @return pointer to the message body memory
 */
char* dbus_message_get_body (DBusMessage *message);

/**
 * Adjust the length of the message body buffer. The memory will be reallocated
 * if the new length is bigger than the already allocated size.
 *
 * @see dbus_message_get_body_allocated
 * @param message the message
 * @param length the new length of the body
 * @return #TRUE if successful
 */
dbus_bool_t dbus_message_set_body_length (DBusMessage *message, int length);


/**
 * Gets the length of the message body buffer.
 *
 * @param message the message
 * @param length the new length of the body
 * @return the length of the body buffer
 */
int dbus_message_get_body_length (DBusMessage *message);

/**
 * Gets the allocated memory size used to hold the message body.
 *
 * @param message the message
 * @return size of the allocated message body memory
 */
int dbus_message_get_body_allocated (DBusMessage *message);


