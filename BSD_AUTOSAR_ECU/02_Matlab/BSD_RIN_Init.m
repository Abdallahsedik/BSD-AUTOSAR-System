%% BSD_RIN_Init.m   -workspace initialization
% PRJ-002-RIN
% Parameter	Description	Value


%% simulation parameters

RIN_Step_Size = 0.020  ; %(25 ms)
RIN_Stop_Time = 2.0;    %(2s)

%% simulation parameters for warning swc

WRN_Step_Size = 0.020  ; %(1 ms)
WRN_Stop_Time = 2.0;    %(2s)
%% Calibration parameters

%Minimum valid raw distance	
RADAR_RAW_MIN = single(50);

%Maximum valid raw distance
RADAR_RAW_MAX= single(500);

%Meters per raw count
RADAR_RESOLUTION_M=single(0.01);

%Distance output while status is RADAR_FAIL
RADAR_DIST_FAILSAFE_M=10.0;

%Status_Raw code meaning "sensor healthy"
RADAR_STATUS_VALID_CODE	=uint8(0x00);


%% init condition 
% Cycles without a new frame before timeout
RADAR_TIMEOUT_CYCLES=single(25); %(500 ms / 20 ms)
% Consecutive valid samples needed to recover
%% hysteresis
RADAR_RECOVERY_CNT=single(3);

RIN_Counter =uint8(0);



