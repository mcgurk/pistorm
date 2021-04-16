// SPDX-License-Identifier: MIT

#define NUM_UNITS 7
#define PISCSI_OFFSET  0x80000000
#define PISCSI_REGSIZE 0x00010000
#define PISCSI_UPPER   0x80010000

#define SCSIERR_TIMEOUT  (1 << 7)
#define SCSIERR_PARAM    (1 << 6)
#define SCSIERR_ADDRESS  (1 << 5)
#define SCSIERR_ERASESEQ (1 << 4)
#define SCSIERR_CRC      (1 << 3)
#define SCSIERR_ILLEGAL  (1 << 2)
#define SCSIERR_ERASERES (1 << 1)
#define SCSIERR_IDLE     (1 << 0)

enum piscsi_stuff {
    PISCSI_BLOCK_SIZE = 512,
    PISCSI_TRACK_SECTORS = 2048,
};

enum piscsi_cmds {
    PISCSI_CMD_WRITE    = 0x00,
    PISCSI_CMD_READ     = 0x02,
    PISCSI_CMD_DRVNUM   = 0x04,
    PISCSI_CMD_DRVTYPE  = 0x06,
    PISCSI_CMD_BLOCKS   = 0x08,
    PISCSI_CMD_CYLS     = 0x0A,
    PISCSI_CMD_HEADS    = 0x0C,
    PISCSI_CMD_SECS     = 0x0E,
    PISCSI_CMD_ADDR1    = 0x10,
    PISCSI_CMD_ADDR2    = 0x14,
    PISCSI_CMD_ADDR3    = 0x18,
    PISCSI_CMD_ADDR4    = 0x1C,
    PISCSI_CMD_DEBUGME  = 0x20,
    PISCSI_CMD_DRIVER   = 0x40,
    PISCSI_CMD_NEXTPART = 0x44,
    PISCSI_CMD_GETPART  = 0x48,
    PISCSI_CMD_GETPRIO  = 0x4C,
    PISCSI_CMD_WRITE64  = 0x50,
    PISCSI_CMD_READ64   = 0x52,
    PISCSI_CMD_CHECKFS  = 0x60,
    PISCSI_CMD_NEXTFS   = 0x64,
    PISCSI_CMD_COPYFS   = 0x68,
    PISCSI_CMD_FSSIZE   = 0x6C,
    PISCSI_CMD_SETFSH   = 0x70,
    PISCSI_DBG_MSG      = 0x1000,
    PISCSI_DBG_VAL1     = 0x1010,
    PISCSI_DBG_VAL2     = 0x1014,
    PISCSI_DBG_VAL3     = 0x1018,
    PISCSI_DBG_VAL4     = 0x101C,
    PISCSI_DBG_VAL5     = 0x1020,
    PISCSI_DBG_VAL6     = 0x1024,
    PISCSI_DBG_VAL7     = 0x1028,
    PISCSI_DBG_VAL8     = 0x102C,
    PISCSI_CMD_ROM      = 0x4000,
};

enum piscsi_dbg_msgs {
    DBG_INIT,
    DBG_OPENDEV,
    DBG_CLOSEDEV,
    DBG_CHS,
    DBG_IOCMD,
    DBG_CLEANUP,
    DBG_BEGINIO,
    DBG_ABORTIO,
    DBG_SCSICMD,
    DBG_SCSI_FORMATDEVICE,
    DBG_SCSI_RDG,
    DBG_SCSI_UNKNOWN_MODESENSE,
    DBG_SCSI_UNKNOWN_COMMAND,
    DBG_SCSIERR,
    DBG_IOCMD_UNHANDLED,
    DBG_SCSI_DEBUG_MODESENSE_6,
    DBG_SCSI_DEBUG_MODESENSE_10,
    DBG_SCSICMD_RW6,
    DBG_SCSICMD_RW10,
};

enum scsi_commands {
    SCSICMD_TEST_UNIT_READY = 0x00,
    SCSICMD_REWIND = 0x01,
    SCSICMD_REQUEST_SENSE = 0x03,
    SCSICMD_FORMAT = 0x04,
    SCSICMD_READ_BLOCK_LIMITS = 0x05,
    SCSICMD_REASSIGN_BLOCKS = 0x07,
    SCSICMD_INITIALIZE_ELEMENT_STATUS = 0x07,
    SCSICMD_READ_6 = 0x08,
    SCSICMD_WRITE_6 = 0x0A,
    SCSICMD_SEEK_6 = 0x0B,
    SCSICMD_READ_REVERSE_6 = 0x0F,
    SCSICMD_WRITE_FILEMARKS_6 = 0x10,
    SCSICMD_SPACE_6 = 0x11,
    SCSICMD_INQUIRY = 0x12,
    SCSICMD_VERIFY_6 = 0x13,
    SCSICMD_RECOVER_BUFFERED_DATA = 0x14,
    SCSICMD_MODE_SELECT_6 = 0x15,
    SCSICMD_RESERVE_6 = 0x16,
    SCSICMD_RELEASE_6 = 0x17,
    SCSICMD_COPY = 0x18,
    SCSICMD_ERASE_6 = 0x19,
    SCSICMD_MODE_SENSE_6 = 0x1A,
    SCSICMD_START_STOP_UNIT = 0x1B,
    SCSICMD_LOAD_UNLOAD = 0x1B,
    SCSICMD_RECEIVE_DIAGNOSTIC_RESULTS = 0x1C,
    SCSICMD_SEND_DIAGNOSTIC = 0x1D,
    SCSICMD_PREVENT_ALLOW_MEDIUM_REMOVAL = 0x1E,
    SCSICMD_READ_FORMAT_CAPACITIES = 0x23,
    SCSICMD_READ_CAPACITY_10 = 0x25,
    SCSICMD_READ_10 = 0x28,
    SCSICMD_READ_GENERATION = 0x29,
    SCSICMD_WRITE_10 = 0x2A,
    SCSICMD_SEEK_10 = 0x2B,
    SCSICMD_LOCATE_10 = 0x2B,
    SCSICMD_ERASE_10 = 0x2C,
    SCSICMD_READ_UPDATED_BLOCK = 0x2D,
    SCSICMD_WRITE_AND_VERIFY_10 = 0x2E,
    SCSICMD_VERIFY_10 = 0x2F,
    SCSICMD_SET_LIMITS_10 = 0x33,
    SCSICMD_PREFETCH_10 = 0x34,
    SCSICMD_READ_POSITION = 0x34,
    SCSICMD_SYNCHRONIZE_CACHE_10 = 0x35,
    SCSICMD_LOCK_UNLOCK_CACHE_10 = 0x36,
    SCSICMD_READ_DEFECT_DATA_10 = 0x37,
    SCSICMD_INITIALIZE_ELEMENT_STATUS_WITH_RANGE = 0x37,
    SCSICMD_MEDIUM_SCAN = 0x38,
    SCSICMD_COMPARE = 0x39,
    SCSICMD_COPY_AND_VERIFY = 0x3A,
    SCSICMD_WRITE_BUFFER = 0x3B,
    SCSICMD_READ_BUFFER = 0x3C,
    SCSICMD_UPDATE_BLOCK = 0x3D,
    SCSICMD_READ_LONG_10 = 0x3E,
    SCSICMD_WRITE_LONG_10 = 0x3F,
    SCSICMD_CHANGE_DEFINITION = 0x40,
    SCSICMD_WRITE_SAME_10 = 0x41,
    SCSICMD_UNMAP = 0x42,
    SCSICMD_READ_TOC_PMA_ATIP = 0x43,
    SCSICMD_REPORT_DENSITY_SUPPORT = 0x44,
    SCSICMD_PLAY_AUDIO_10 = 0x45,
    SCSICMD_GET_CONFIGURATION = 0x46,
    SCSICMD_PLAY_AUDIO_MSF = 0x47,
    SCSICMD_SANITIZE = 0x48,
    SCSICMD_GET_EVENT_STATUS_NOTIFICATION = 0x4A,
    SCSICMD_PAUSE_RESUME = 0x4B,
    SCSICMD_LOG_SELECT = 0x4C,
    SCSICMD_LOG_SENSE = 0x4D,
    SCSICMD_XDWRITE_10 = 0x50,
    SCSICMD_XPWRITE_10 = 0x51,
    SCSICMD_READ_DISC_INFORMATION = 0x51,
    SCSICMD_XDREAD_10 = 0x52,
    SCSICMD_XDWRITEREAD_10 = 0x53,
    SCSICMD_SEND_OPC_INFORMATION = 0x54,
    SCSICMD_MODE_SELECT_10 = 0x55,
    SCSICMD_RESERVE_10 = 0x56,
    SCSICMD_RELEASE_10 = 0x57,
    SCSICMD_REPAIR_TRACK = 0x58,
    SCSICMD_MODE_SENSE_10 = 0x5A,
    SCSICMD_CLOSE_TRACK_SESSION = 0x5B,
    SCSICMD_READ_BUFFER_CAPACITY = 0x5C,
    SCSICMD_SEND_CUE_SHEET = 0x5D,
    SCSICMD_PERSISTENT_RESERVE_IN = 0x5E,
    SCSICMD_PERSISTENT_RESERVE_OUT = 0x5F,
    SCSICMD_EXTENDED_CDB = 0x7E,
    SCSICMD_VARIABLELENGTH_CDB = 0x7F,
    SCSICMD_XDWRITE_EXTENDED_16 = 0x80,
    SCSICMD_WRITE_FILEMARKS_16 = 0x80,
    SCSICMD_READ_REVERSE_16 = 0x81,
    SCSICMD_3RDPARTY_COPY_OUT_CMDS = 0x83,
    SCSICMD_3RDPARTY_COPY_IN_CMDS = 0x84,
    SCSICMD_ATA_PASSTHROUGH_16 = 0x85,
    SCSICMD_ACCESS_CONTROL_IN = 0x86,
    SCSICMD_ACCESS_CONTROL_OUT = 0x87,
    SCSICMD_READ_16 = 0x88,
    SCSICMD_COMPARE_AND_WRITE = 0x89,
    SCSICMD_WRITE_16 = 0x8A,
    SCSICMD_ORWRITE = 0x8B,
    SCSICMD_READ_ATTRIBUTE = 0x8C,
    SCSICMD_WRITE_ATTRIBUTE = 0x8D,
    SCSICMD_WRITE_AND_VERIFY_16 = 0x8E,
    SCSICMD_VERIFY_16 = 0x8F,
    SCSICMD_PREFETCH_16 = 0x90,
    SCSICMD_SYNCHRONIZE_CACHE_16 = 0x91,
    SCSICMD_SPACE_16 = 0x91,
    SCSICMD_LOCK_UNLOCK_CACHE_16 = 0x92,
    SCSICMD_LOCATE_16 = 0x92,
    SCSICMD_WRITE_SAME_16 = 0x93,
    SCSICMD_ERASE_16 = 0x93,
    SCSICMD_SERVICE_ACTION_BIDIRECTIONAL = 0x9D,
    SCSICMD_SERVICE_ACTION_IN_16 = 0x9E,
    SCSICMD_SERVICE_ACTION_OUT_16 = 0x9F,
    SCSICMD_REPORT_LUNS = 0xA0,
    SCSICMD_ATA_PASSTHROUGH_12 = 0xA1,
    SCSICMD_SECURITY_PROTOCOL_IN = 0xA2,
    SCSICMD_MAINTENANCE_IN = 0xA3,
    SCSICMD_MAINTENANCE_OUT = 0xA4,
    SCSICMD_REPORT_KEY = 0xA4,
    SCSICMD_MOVE_MEDIUM = 0xA5,
    SCSICMD_PLAY_AUDIO_12 = 0xA5,
    SCSICMD_EXCHANGE_MEDIUM = 0xA6,
    SCSICMD_MOVE_MEDIUM_ATTACHED = 0xA7,
    SCSICMD_READ_12 = 0xA8,
    SCSICMD_SERVICE_ACTION_OUT_12 = 0xA9,
    SCSICMD_WRITE_12 = 0xAA,
    SCSICMD_SERVICE_ACTION_IN_12 = 0xAB,
    SCSICMD_ERASE_12 = 0xAC,
    SCSICMD_READ_DVD_STRUCTURE = 0xAD,
    SCSICMD_WRITE_AND_VERIFY_12 = 0xAE,
    SCSICMD_VERIFY_12 = 0xAF,
    SCSICMD_SEARCH_DATA_HIGH_12 = 0xB0,
    SCSICMD_SEARCH_DATA_EQUAL_12 = 0xB1,
    SCSICMD_SEARCH_DATA_LOW_12 = 0xB2,
    SCSICMD_SET_LIMITS_12 = 0xB3,
    SCSICMD_READ_ELEMENT_STATUS_ATTACHED = 0xB4,
    SCSICMD_SECURITY_PROTOCOL_OUT = 0xB5,
    SCSICMD_SEND_VOLUME_TAG = 0xB6,
    SCSICMD_READ_DEFECT_DATA_12 = 0xB7,
    SCSICMD_READ_ELEMENT_STATUS = 0xB8,
    SCSICMD_READ_CD_MSF = 0xB9,
    SCSICMD_REDUNDANCY_GROUP_IN = 0xBA,
    SCSICMD_REDUNDANCY_GROUP_OUT = 0xBB,
    SCSICMD_SPARE_IN = 0xBC,
    SCSICMD_SPARE_OUT = 0xBD,
    SCSICMD_VOLUME_SET_IN = 0xBE,
    SCSICMD_VOLUME_SET_OUT = 0xBF,
};

#define TD_READ64           24
#define TD_WRITE64          25
#define TD_SEEK64           26
#define TD_FORMAT64         27

#define NSCMD_TD_READ64     0xC000
#define NSCMD_TD_WRITE64    0xC001
#define NSCMD_TD_SEEK64     0xC002
#define NSCMD_TD_FORMAT64   0xC003
