DROP TABLE IF EXISTS "defaults";
    CREATE TABLE "defaults" (
        "account" TEXT PRIMARY KEY NOT NULL,
        "active" BOOL DEFAULT (0),
        "locked" BOOL DEFAULT (0),
        "bounded" BOOL,
        "boundedByDay" BOOL DEFAULT (null) ,
        "limitAccessOnDuration" BOOL DEFAULT (null) ,
        "limitAccessOnDurationEachDay" BOOL DEFAULT (null) ,
        "limitAccessOnDurationEachDayTime" TEXT DEFAULT (null) ,
        "limitAccessOnDurationPerDay" BOOL DEFAULT (null) ,
        "limitAccessOnDurationPerDayTime" TEXT DEFAULT (null) ,
        "limitAccessOnTimeFrame" BOOL DEFAULT (null) ,
        "limitAccessOnTimeFrameEachDay" BOOL DEFAULT (null) ,
        "limitAccessOnTimeFrameEachDayTime" TEXT DEFAULT (null) ,
        "limitAccessOnTimeFramePerDay" BOOL DEFAULT (null) ,
        "limitAccessOnTimeFramePerDayTime" TEXT DEFAULT (null) );
INSERT INTO "defaults" VALUES('default','false', 'false', 'false','false','true','false','01:00','true','02:00,03:00,04:00,05:00,06:00,07:00,08:00','false','false','07:00,22:00','true','02:00.12:00, 03:00.13:00, 04:00.14:00, 05:00.15:00, 06:00.16:00,07:00.17:00,08:00.18:00');

DROP TABLE IF EXISTS "limits";
    CREATE TABLE "limits" (
        "account" TEXT PRIMARY KEY NOT NULL,
        "locked" BOOL DEFAULT (0),
        "active" BOOL DEFAULT (0),
        "bounded" BOOL,
        "boundedByDay" BOOL DEFAULT (null) ,
        "limitAccessOnDuration" BOOL DEFAULT (null) ,
        "limitAccessOnDurationEachDay" BOOL DEFAULT (null) ,
        "limitAccessOnDurationEachDayTime" TEXT DEFAULT (null) ,
        "limitAccessOnDurationPerDay" BOOL DEFAULT (null) ,
        "limitAccessOnDurationPerDayTime" TEXT DEFAULT (null) ,
        "limitAccessOnTimeFrame" BOOL DEFAULT (null) ,
        "limitAccessOnTimeFrameEachDay" BOOL DEFAULT (null) ,
        "limitAccessOnTimeFrameEachDayTime" TEXT DEFAULT (null) ,
        "limitAccessOnTimeFramePerDay" BOOL DEFAULT (null) ,
        "limitAccessOnTimeFramePerDayTime" TEXT DEFAULT (null) );

