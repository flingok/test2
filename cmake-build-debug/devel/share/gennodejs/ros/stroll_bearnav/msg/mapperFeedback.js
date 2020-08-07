// Auto-generated. Do not edit!

// (in-package stroll_bearnav.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class mapperFeedback {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.fileName = null;
    }
    else {
      if (initObj.hasOwnProperty('fileName')) {
        this.fileName = initObj.fileName
      }
      else {
        this.fileName = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type mapperFeedback
    // Serialize message field [fileName]
    bufferOffset = _serializer.string(obj.fileName, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type mapperFeedback
    let len;
    let data = new mapperFeedback(null);
    // Deserialize message field [fileName]
    data.fileName = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.fileName.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'stroll_bearnav/mapperFeedback';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0c96d4662a80949a4927729271153923';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    #feedback
    string fileName
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new mapperFeedback(null);
    if (msg.fileName !== undefined) {
      resolved.fileName = msg.fileName;
    }
    else {
      resolved.fileName = ''
    }

    return resolved;
    }
};

module.exports = mapperFeedback;
