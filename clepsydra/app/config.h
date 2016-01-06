#ifndef CONFIG_H
#define CONFIG_H

#define MAP_SETTINGS_INFO       "var"

#define KEY_ACCOUNT_LOCKED              "AccountLocked"

#define CLEPSYDRADIR                    "CLEPSYDRADIR"          // i.e etc/clepsydra
#define CLEPSYDRA_WORK                  "CLEPSYDRAWORK"
#define CLEPSYDRA_LOGDIR                "CLEPSYDRALOGDIR"
#define CLEPSYDRA_GRACEPERIOD           "CLEPSYDRAGRACEPERIOD"

#define CLEPSYDRA_LIMITED               "limited"
#define CLEPSYDRA_LOCKED                "locked"

#define CLEPSYDRA_LIMIT_BOUNDED         "bounded"
#define CLEPSYDRA_LIMIT_BOUNDEDBYDAY    "boundedByDay"

#define CLEPSYDRA_LIMIT_BOUNDED         "bounded"
#define CLEPSYDRA_LIMIT_BOUNDEDBYDAY    "boundedByDay"
#define CLEPSYDRA_LIMIT_LIMITS          "limits"
#define CLEPSYDRA_LIMIT_TIME_FROM       "time_from"
#define CLEPSYDRA_LIMIT_TIME_TO         "time_to"

#define CLEPSYDRA_LIMIT_LIMITSBYDAY     "limitedByday"

#define CLEPSYDRA_LIMIT_ACCESS_ON_DURATION             "ckLimitAccessTimeDuration"
#define CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_EACH_DAY    "limitAccessOnDurationEachDay"
#define CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_EACH_DAY_TIME "limitAccessOnDurationEachDayTime"
#define CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_PER_DAY     "limitAccessOnDurationPerDay"
#define CLEPSYDRA_LIMIT_ACCESS_ON_DURATION_PER_DAY_TIME "limitAccessOnDurationPerDayTime"

#define CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME             "LimitAccessOnTimeFrame"
#define CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_EACH_DAY    "LimitAccessOnTimeFrameEachDay"
#define CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_PER_DAY     "LimitAccessOnTimeFramePerDay"
#define CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_EACH_DAY_TIME "LimitAccessOnTimeFrameEachDayTime"
#define CLEPSYDRA_LIMIT_ACCESS_ON_TIMEFRAME_PER_DAY_TIME "LimitAccessOnTimeFramePerDayTime"

#define CLEPSYDRA_CONFIG_FOLDER             "/etc/clepsydra/"
//#define CLEPSYDRA_WORKING_FOLDER            "/var/lib/clepsydra/"
#define CLEPSYDRA_WORKING_FOLDER            "/tmp/"
#define CLEPSYDRA_CONFIG_FILENAME           "clepsydra.conf"
#define CLEPSYDRA_JSON_DEFAULTS_FILENAME    "clepsydradefault.json"
#define CLEPSYDRA_JSON_USERDATA_FILENAME    "clepsydralimits.json"

#endif // CONFIG_H

