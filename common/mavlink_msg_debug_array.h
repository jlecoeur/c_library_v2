#pragma once
// MESSAGE DEBUG_ARRAY PACKING

#define MAVLINK_MSG_ID_DEBUG_ARRAY 350

MAVPACKED(
typedef struct __mavlink_debug_array_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 float data[60]; /*< data*/
 uint8_t id; /*< Unique ID used to discriminate between arrays*/
 char name[10]; /*< Name, for human-friendly display in QGC*/
}) mavlink_debug_array_t;

#define MAVLINK_MSG_ID_DEBUG_ARRAY_LEN 255
#define MAVLINK_MSG_ID_DEBUG_ARRAY_MIN_LEN 255
#define MAVLINK_MSG_ID_350_LEN 255
#define MAVLINK_MSG_ID_350_MIN_LEN 255

#define MAVLINK_MSG_ID_DEBUG_ARRAY_CRC 123
#define MAVLINK_MSG_ID_350_CRC 123

#define MAVLINK_MSG_DEBUG_ARRAY_FIELD_DATA_LEN 60
#define MAVLINK_MSG_DEBUG_ARRAY_FIELD_NAME_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DEBUG_ARRAY { \
    350, \
    "DEBUG_ARRAY", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_debug_array_t, time_boot_ms) }, \
         { "data", NULL, MAVLINK_TYPE_FLOAT, 60, 4, offsetof(mavlink_debug_array_t, data) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 244, offsetof(mavlink_debug_array_t, id) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 10, 245, offsetof(mavlink_debug_array_t, name) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DEBUG_ARRAY { \
    "DEBUG_ARRAY", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_debug_array_t, time_boot_ms) }, \
         { "data", NULL, MAVLINK_TYPE_FLOAT, 60, 4, offsetof(mavlink_debug_array_t, data) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 244, offsetof(mavlink_debug_array_t, id) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 10, 245, offsetof(mavlink_debug_array_t, name) }, \
         } \
}
#endif

/**
 * @brief Pack a debug_array message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param id Unique ID used to discriminate between arrays
 * @param name Name, for human-friendly display in QGC
 * @param data data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_array_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t id, const char *name, const float *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEBUG_ARRAY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 244, id);
    _mav_put_float_array(buf, 4, data, 60);
    _mav_put_char_array(buf, 245, name, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN);
#else
    mavlink_debug_array_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.id = id;
    mav_array_memcpy(packet.data, data, sizeof(float)*60);
    mav_array_memcpy(packet.name, name, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEBUG_ARRAY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DEBUG_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_CRC);
}

/**
 * @brief Pack a debug_array message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param id Unique ID used to discriminate between arrays
 * @param name Name, for human-friendly display in QGC
 * @param data data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_array_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t id,const char *name,const float *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEBUG_ARRAY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 244, id);
    _mav_put_float_array(buf, 4, data, 60);
    _mav_put_char_array(buf, 245, name, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN);
#else
    mavlink_debug_array_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.id = id;
    mav_array_memcpy(packet.data, data, sizeof(float)*60);
    mav_array_memcpy(packet.name, name, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEBUG_ARRAY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DEBUG_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_CRC);
}

/**
 * @brief Encode a debug_array struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param debug_array C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_debug_array_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_debug_array_t* debug_array)
{
    return mavlink_msg_debug_array_pack(system_id, component_id, msg, debug_array->time_boot_ms, debug_array->id, debug_array->name, debug_array->data);
}

/**
 * @brief Encode a debug_array struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param debug_array C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_debug_array_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_debug_array_t* debug_array)
{
    return mavlink_msg_debug_array_pack_chan(system_id, component_id, chan, msg, debug_array->time_boot_ms, debug_array->id, debug_array->name, debug_array->data);
}

/**
 * @brief Send a debug_array message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param id Unique ID used to discriminate between arrays
 * @param name Name, for human-friendly display in QGC
 * @param data data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_debug_array_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint8_t id, const char *name, const float *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEBUG_ARRAY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 244, id);
    _mav_put_float_array(buf, 4, data, 60);
    _mav_put_char_array(buf, 245, name, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG_ARRAY, buf, MAVLINK_MSG_ID_DEBUG_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_CRC);
#else
    mavlink_debug_array_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.id = id;
    mav_array_memcpy(packet.data, data, sizeof(float)*60);
    mav_array_memcpy(packet.name, name, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG_ARRAY, (const char *)&packet, MAVLINK_MSG_ID_DEBUG_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_CRC);
#endif
}

/**
 * @brief Send a debug_array message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_debug_array_send_struct(mavlink_channel_t chan, const mavlink_debug_array_t* debug_array)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_debug_array_send(chan, debug_array->time_boot_ms, debug_array->id, debug_array->name, debug_array->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG_ARRAY, (const char *)debug_array, MAVLINK_MSG_ID_DEBUG_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_CRC);
#endif
}

#if MAVLINK_MSG_ID_DEBUG_ARRAY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_debug_array_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint8_t id, const char *name, const float *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 244, id);
    _mav_put_float_array(buf, 4, data, 60);
    _mav_put_char_array(buf, 245, name, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG_ARRAY, buf, MAVLINK_MSG_ID_DEBUG_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_CRC);
#else
    mavlink_debug_array_t *packet = (mavlink_debug_array_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->id = id;
    mav_array_memcpy(packet->data, data, sizeof(float)*60);
    mav_array_memcpy(packet->name, name, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG_ARRAY, (const char *)packet, MAVLINK_MSG_ID_DEBUG_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_ARRAY_CRC);
#endif
}
#endif

#endif

// MESSAGE DEBUG_ARRAY UNPACKING


/**
 * @brief Get field time_boot_ms from debug_array message
 *
 * @return Timestamp (milliseconds since system boot)
 */
static inline uint32_t mavlink_msg_debug_array_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field id from debug_array message
 *
 * @return Unique ID used to discriminate between arrays
 */
static inline uint8_t mavlink_msg_debug_array_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  244);
}

/**
 * @brief Get field name from debug_array message
 *
 * @return Name, for human-friendly display in QGC
 */
static inline uint16_t mavlink_msg_debug_array_get_name(const mavlink_message_t* msg, char *name)
{
    return _MAV_RETURN_char_array(msg, name, 10,  245);
}

/**
 * @brief Get field data from debug_array message
 *
 * @return data
 */
static inline uint16_t mavlink_msg_debug_array_get_data(const mavlink_message_t* msg, float *data)
{
    return _MAV_RETURN_float_array(msg, data, 60,  4);
}

/**
 * @brief Decode a debug_array message into a struct
 *
 * @param msg The message to decode
 * @param debug_array C-struct to decode the message contents into
 */
static inline void mavlink_msg_debug_array_decode(const mavlink_message_t* msg, mavlink_debug_array_t* debug_array)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    debug_array->time_boot_ms = mavlink_msg_debug_array_get_time_boot_ms(msg);
    mavlink_msg_debug_array_get_data(msg, debug_array->data);
    debug_array->id = mavlink_msg_debug_array_get_id(msg);
    mavlink_msg_debug_array_get_name(msg, debug_array->name);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DEBUG_ARRAY_LEN? msg->len : MAVLINK_MSG_ID_DEBUG_ARRAY_LEN;
        memset(debug_array, 0, MAVLINK_MSG_ID_DEBUG_ARRAY_LEN);
    memcpy(debug_array, _MAV_PAYLOAD(msg), len);
#endif
}
