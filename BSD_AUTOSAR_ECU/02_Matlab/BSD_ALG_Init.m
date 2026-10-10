%% BSD_ALG_Init.m - Workspace initialization
% PRJ-002-ALG
% Parameter          Description                              Value

%% Simulation parameters
ALG_Step_Size = 0.020 ;   %(20 ms)
ALG_Stop_Time = 2.0;     %(2s)

%% Calibration parameters

% Distance threshold for warning (meters)
BSD_WARN_DISTANCE_M = single(3.0);

% Speed limit to disable BSD (Highway suppression) (km/h)
VSPD_SUPPRESSION_THRESHOLD = single(100.0);