// This file is generated by Ember Desktop.  Please do not edit manually.
//
//

// This is a set of generated functions that parse the
// the incomming message, and call appropriate command handler.



#include PLATFORM_HEADER
#ifdef EZSP_HOST
// Includes needed for ember related functions for the EZSP host
#include "stack/include/error.h"
#include "stack/include/ember-types.h"
#include "app/util/ezsp/ezsp-protocol.h"
#include "app/util/ezsp/ezsp.h"
#include "app/util/ezsp/ezsp-utils.h"
#include "app/util/ezsp/serial-interface.h"
#else
// Includes needed for ember related functions for the EM250
#include "stack/include/ember.h"
#endif // EZSP_HOST

#include "app/framework/util/util.h"
#include "af-structs.h"
#include "call-command-handler.h"
#include "command-id.h"
#include "callback.h"

static EmberAfStatus status(bool wasHandled, bool clusterExists, bool mfgSpecific)
{
  if (wasHandled) {
    return EMBER_ZCL_STATUS_SUCCESS;
  } else if (mfgSpecific) {
    return EMBER_ZCL_STATUS_UNSUP_MANUF_CLUSTER_COMMAND;
  } else if (clusterExists) {
    return EMBER_ZCL_STATUS_UNSUP_CLUSTER_COMMAND;
  } else {
    return EMBER_ZCL_STATUS_UNSUPPORTED_CLUSTER;
  }
}

// Main command parsing controller.
EmberAfStatus emberAfClusterSpecificCommandParse(EmberAfClusterCommand *cmd)
{
  if (cmd->direction == ZCL_DIRECTION_CLIENT_TO_SERVER
      && emberAfContainsServer(cmd->apsFrame->destinationEndpoint,
                               cmd->apsFrame->clusterId)) {
    switch (cmd->apsFrame->clusterId) {
    case ZCL_BASIC_CLUSTER_ID:
      return emberAfBasicClusterServerCommandParse(cmd);
    case ZCL_IDENTIFY_CLUSTER_ID:
      return emberAfIdentifyClusterServerCommandParse(cmd);
    case ZCL_IAS_ZONE_CLUSTER_ID:
      return emberAfIasZoneClusterServerCommandParse(cmd);
    case ZCL_IAS_WD_CLUSTER_ID:
      return emberAfIasWdClusterServerCommandParse(cmd);
    }
  }
  return status(false, false, cmd->mfgSpecific);
}

// Cluster: Basic, server
EmberAfStatus emberAfBasicClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_RESET_TO_FACTORY_DEFAULTS_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfBasicClusterResetToFactoryDefaultsCallback();
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: Identify, server
EmberAfStatus emberAfIdentifyClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_IDENTIFY_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t identifyTime;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        identifyTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfIdentifyClusterIdentifyCallback(identifyTime);
        break;
      }
    case ZCL_IDENTIFY_QUERY_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfIdentifyClusterIdentifyQueryCallback();
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: IAS Zone, server
EmberAfStatus emberAfIasZoneClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_ZONE_ENROLL_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t enrollResponseCode;  // Ver.: always
        uint8_t zoneId;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        enrollResponseCode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1;
        zoneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfIasZoneClusterZoneEnrollResponseCallback(enrollResponseCode,
                                                                     zoneId);
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: IAS WD, server
EmberAfStatus emberAfIasWdClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_START_WARNING_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t warningInfo;  // Ver.: always
        uint16_t warningDuration;  // Ver.: always
        uint8_t strobeDutyCycle;  // Ver.: since ha-1.2-05-3520-29
        uint8_t strobeLevel;  // Ver.: since ha-1.2-05-3520-29
        // Command is not a fixed length
        if (cmd->bufLen < payloadOffset + 1) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        warningInfo = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1;
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        warningDuration = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        if ( ( cmd->bufLen < payloadOffset + 1)) {
          // Argument is not always present:
          // - it is present only in versions higher than: ha-1.2-05-3520-29
          strobeDutyCycle = 0xFF;
        } else {
          strobeDutyCycle = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1;
        }
        if ( ( cmd->bufLen < payloadOffset + 1)) {
          // Argument is not always present:
          // - it is present only in versions higher than: ha-1.2-05-3520-29
          strobeLevel = 0xFF;
        } else {
          strobeLevel = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        }
        wasHandled = emberAfIasWdClusterStartWarningCallback(warningInfo,
                                                             warningDuration,
                                                             strobeDutyCycle,
                                                             strobeLevel);
        break;
      }
    case ZCL_SQUAWK_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t squawkInfo;  // Ver.: always
        // Command is fixed length: 1
        if (cmd->bufLen < payloadOffset + 1) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        squawkInfo = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfIasWdClusterSquawkCallback(squawkInfo);
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}
