%% BSD_VSG_Init.m   -workspace initialization
% PRJ-002-RIN
% Parameter	Description	Value


%% simulation parameters

VSG_Step_Size = 0.020  ; %(20 ms)
VSG_Stop_Time = 2.0;    %(2s)
%% Calibration parameters

%% speed
%The SWC shall convert speed using Vehicle_Speed = Vehicle_Speed_Raw × VSPD_RESOLUTION_KMH
VSPD_RESOLUTION_KMH = single(0.01);

%Minimum valid raw speed	
VSPD_RAW_MIN = single(0);

%Minimum valid raw speed	
VSPD_RAW_MAX = single(30000);

%VSPD FAIL SAFE KMH	
VSPD_FAILSAFE_KMH = single(0);

VSPD_SUPPRESSION_THRESHOLD= single(100.0);

%% steering

%The SWC shall convert steering angle using Steering_Angle = Raw_steering × STEER_RESOLUTION_DEG
STEER_RESOLUTION_DEG = single(0.1);


% The SWC shall set Steering_Status to SIGNAL_FAIL when Raw_steering is outside [STEER_RAW_MIN, STEER_RAW_MAX]
%Minimum valid Raw_steering	
STEER_RAW_MIN  = single(-9000);

%Minimum valid Raw_steering	
STEER_RAW_MAX = single(9000);


%streer  FAIL SAFE KMH	
STEER_FAILSAFE_DEG = single(0.0);

%% Consecutive valid samples needed to recover
% hysteresis
VSG_RECOVERY_CNT = uint8(3);
%% GEAR

GEAR_FAILSAFE =  Gear_T.GEAR_PARK ;


%% diagram
DIAG_DEBOUNCE_CNT = uint8(1);   % per SRS-PRJ-002-DIA §5.2
