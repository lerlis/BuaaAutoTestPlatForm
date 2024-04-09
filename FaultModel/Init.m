load MavLinkStruct;

%control param
MY_TAU_P_P = Pixhawk_CSC.Parameter( {single(1.5), 'MY_TAU_P_P'}  );
MY_TAU_P_A = Pixhawk_CSC.Parameter( {single(0), 'MY_TAU_P_A'}  );
MY_TAU_P_P_YAW = Pixhawk_CSC.Parameter( {single(0.1), 'MY_TAU_P_P_YAW'}  );
MY_TAU_P_A_YAW = Pixhawk_CSC.Parameter( {single(0), 'MY_TAU_P_A_YAW'}  );

MY_RATE_P = Pixhawk_CSC.Parameter( {single(12), 'MY_RATE_P'}  );
MY_RATE_P_YAW = Pixhawk_CSC.Parameter( {single(0.3), 'MY_RATE_P_YAW'}  );

MY_ATT_P = Pixhawk_CSC.Parameter( {single(8), 'MY_ATT_P'}  );
MY_ATT_P_YAW = Pixhawk_CSC.Parameter( {single(0), 'MY_ATT_P_YAW'}  );

MY_POS_P = Pixhawk_CSC.Parameter( {single(1.1), 'MY_POS_P'}  );
MY_VEL_P = Pixhawk_CSC.Parameter( {single(1.0), 'MY_VEL_P'}  );

MY_SAT_AD = Pixhawk_CSC.Parameter({single(0.13), 'MY_SAT_AD'} );

Ts = 1/400;
Tmotorbar = (0.035);%模拟实际下的Tmotor的估计值

Tf = 0.06;

g  = (9.8);
m  = (0.752);
c  = (0.0166);
l  = (0.125);
J  = (diag([0.0056 0.0056 0.0104]));
M = ([ 1          1          1         1;
      -0.7071*l  -0.7071*l   0.7071*l  0.7071*l;
       0.7071*l  -0.7071*l  -0.7071*l  0.7071*l;
       c         -c          c        -c]);
      
% B = [0.25   -1.4142/(4*l)     1.4142/(4*l)     1/(4*c);
%      0.25   -1.4142/(4*l)    -1.4142/(4*l)    -1/(4*c);
%      0.25    1.4142/(4*l)    -1.4142/(4*l)     1/(4*c);   
%      0.25    1.4142/(4*l)     1.4142/(4*l)    -1/(4*c)];
    
T00  =single([m*g/4 m*g/4 m*g/4 m*g/4]');

%% EKF Param
ModelParam_envLongitude = 116.2593683;
ModelParam_envLatitude = 40.1540302;
ModelParam_GPSLatLong = [ModelParam_envLatitude ModelParam_envLongitude];
ModelParam_envAltitude = -50; %参考高度，即当前位置海拔高度，也可认为是起飞前初始高度。向下为正


% Define the 32-D ModelInParams vector for external modification
ModelInParams = zeros(32,1);
% initialize the params used in Simulink model
ModelInParams(3)=1;
%load path;
PX4_CONSTANTS_ONE_G = 9.80665;
%Initial condition
ModelInit_PosE = [0,0,0]; % Vehicle postion xyz in the NED earth frame (m)
ModelInit_VelB = [0,0,0]; % Vehicle speed xyz in the NED earth frame (m/s)
ModelInit_AngEuler = [0,0,0]; % Vehicle Euler angle xyz (roll,pitch,yaw) (rad)
ModelInit_RateB = [0,0,0]; % Vehicle angular speed xyz (roll,pitch,yaw) in the body frame (rad/s)
ModelInit_RPM = 0; %Initial motor speed (rad/s)

%UAV model parameter
% default parameters of UAV
% target_mass = 2;
% ModelParam_uavMass = 1.515; %Mass of UAV(kg)

% alpha = target_mass / ModelParam_uavMass;
% ModelParam_uavMass = ModelParam_uavMass * alpha;
% ModelParam_uavJxx = 0.0241 * alpha;  % moment of inertia in body x axis
% ModelParam_uavJyy = 0.0239 * alpha;  % moment of inertia in body y axis
% ModelParam_uavJzz = 0.0386 * alpha;  % moment of inertia in body z axis

% 250 UAV parameters self
% ModelParam_uavMass = 0.9288; %Mass of UAV(kg)
% ModelParam_uavJxx = 0.005094;  % moment of inertia in body x axis
% ModelParam_uavJyy = 0.004670;   % moment of inertia in body y axis
% ModelParam_uavJzz = 0.007823;  % moment of inertia in body z axis

% 200 UAV parameters
% ModelParam_uavMass = 1.0538; %Mass of UAV(kg)
% ModelParam_uavJxx = 0.003191;  % moment of inertia in body x axis
% ModelParam_uavJyy = 0.002998;   % moment of inertia in body y axis
% ModelParam_uavJzz = 0.004826;  % moment of inertia in body z axis

% 450 UAV parameters
ModelParam_uavMass = 2.0843; %Mass of UAV(kg)
ModelParam_uavJxx = 0.01731;  % moment of inertia in body x axis
ModelParam_uavJyy = 0.01977;   % moment of inertia in body y axis
ModelParam_uavJzz = 0.03026;  % moment of inertia in body z axis

% 680 UAV parameters
% ModelParam_uavMass = 4.0681; %Mass of UAV(kg)
% ModelParam_uavJxx = 0.09862;  % moment of inertia in body x axis
% ModelParam_uavJyy = 0.09862;   % moment of inertia in body y axis
% ModelParam_uavJzz = 0.16366;  % moment of inertia in body z axis

%Moment of inertia matrix
ModelParam_uavJ= [ModelParam_uavJxx,0,0;...
    0,ModelParam_uavJyy,0;...
    0,0,ModelParam_uavJzz];
ModelParam_uavType = int8(3); %X-type quadrotor，refer to "SupportedVehicleTypes.docx" for specific definitions
ModelParam_uavMotNumbs = int8(4);  %Number of motors
ModelParam_uavR = 0.225;   %Body radius(m)

% param 450
ModelParam_motorCr=1197.53; % Motor throttle-speed curve slope(rad/s) 1097.53
ModelParam_motorWb=238.2; % Motor speed-throttle curve constant term(rad/s)168.2
% ModelParam_motorT= 0.0519; % Motor inertia time constant(s)
% ModelParam_motorJm = 1.25e-05; % Moment of inertia of motor rotor + propeller(kg.m^2)
adjust_param1 = 0.8;
adjust_param2 = 1.5; % 2.0
ModelParam_rotorCm=1.779e-07 * adjust_param1; % Rotor torque coefficient(kg.m^2)
ModelParam_rotorCt=1.105e-05 * adjust_param2; % Rotor thrust coefficient(kg.m^2)
% ModelParam_motorMinThr = 0.05; % Motor throttle dead zone(kg.m^2)
% 
ModelParam_uavCd = [0.7095, 0.6342, 0.9];   %Damping coefficient(N/(m/s)^2)
% ModelParam_uavCCm = [0.0049 0.0049 0.002118]; % 200
% ModelParam_uavDearo = 0;
ModelParam_GlobalNoiseGainSwitch =0.4; %Noise level gain

% default parameter
% ModelParam_motorCr = 1148; %Motor throttle-speed curve slope(rad/s)
% ModelParam_motorWb =-141.4;  %Motor speed-throttle curve constant term(rad/s)
ModelParam_motorT = 0.02;  %Motor inertia time constant(s)
ModelParam_motorJm = 0.0001287;    %Moment of inertia of motor rotor + propeller(kg.m^2)
%M=Cm*w^2
% ModelParam_rotorCm = 1.779e-07;    %Rotor torque coefficient(kg.m^2)
%T=Ct**w^2
% ModelParam_rotorCt = 1.105e-05;    %Rotor thrust coefficient(kg.m^2)
ModelParam_motorMinThr = 0.05;     %Motor throttle dead zone(kg.m^2)

% ModelParam_uavCd = 0.055;   %Damping coefficient(N/(m/s)^2)
ModelParam_uavCCm = [0.0035 0.0039 0.0034]; %Damping moment coefficient vector(N/(m/s)^2)
ModelParam_uavDearo = 0.12;  %Vertical position difference of Aerodynamic center and gravity center(m)

% ModelParam_GlobalNoiseGainSwitch =0;   %Noise level gain

%Environment Parameter
ModelParam_envGravityAcc = 9.8;  %Gravity acceleration(m/s^2)
ModelParam_envLongitude = 116.259368300000;  %longitude (degree)
ModelParam_envLatitude = 40.1540302;          %Latitude (degree)
ModelParam_GPSLatLong = [ModelParam_envLatitude ModelParam_envLongitude];  %Latitude and longitude
ModelParam_envAltitude = 0;     %Reference height, down is positive
ModelParam_BusSampleRate = 0.001;            %Model sampling rate



ModelParam_timeSampBaro = 0.01;  % Barometer data sample time
ModelParam_timeSampTurbWind = 0.01; % Atmospheric turbulence data sample time
%%%ModelParam_BattModelEnable=int8(0);
ModelParam_BattHoverMinutes=18; %time of endurance for the battery simulation 
ModelParam_BattHoverThr=0.609; % Vehilce hovering time

%GPS Parameter
ModelParam_GPSEphFinal=0.3; % GPS horizontal accuracy
ModelParam_GPSEpvFinal=0.4;  % GPS vertical accuracy
ModelParam_GPSFix3DFix=3;  % GPS fixed index
ModelParam_GPSSatsVisible=15;  % GPS number of satellites


%Noise Parameter
ModelParam_noisePowerAccel = [0.001,0.001,0.002];% accelerometer noise power xyz in Body frame
ModelParam_noiseSampleTimeAccel = 0.001; % accelerometer noise sample time
ModelParam_noisePowerOffGainAccel = 0.04; %accelerometer noise factor without motor vibration
ModelParam_noisePowerOffGainAccelZ = 0.03; %accelerometer Z noise factor without motor vibration
ModelParam_noisePowerOnGainAccel = 0.8; %accelerometer noise factor under motor vibration
ModelParam_noisePowerOnGainAccelZ = 4.5; %accelerometer Z noise factor under motor vibration
ModelParam_noisePowerGyro = [0.00001,0.00001,0.00001]; %gyroscope  noise power xyz in Body frame
ModelParam_noiseSampleTimeGyro = 0.001; % gyroscope noise sample time
ModelParam_noisePowerOffGainGyro = 0.02;  %accelerometer noise factor without motor vibration
ModelParam_noisePowerOffGainGyroZ = 0.025; %accelerometer noise Z factor without motor vibration
ModelParam_noisePowerOnGainGyro = 2;  %accelerometer noise factor under motor vibration
ModelParam_noisePowerOnGainGyroZ = 1; %accelerometer Z noise factor under motor vibration



ModelParam_noisePowerMag = [0.0001,0.0001,0.0001];
ModelParam_noiseSampleTimeMag = 0.01; %magnetometer sample time
ModelParam_noisePowerOffGainMag = 0.02; %magnetometer noise gain without motor magnetic field effect
ModelParam_noisePowerOffGainMagZ = 0.035;
ModelParam_noisePowerOnGainMag = 0.025;  %magnetometer noise gain under motor magnetic field effect
ModelParam_noisePowerOnGainMagZ = 0.05;
ModelParam_noisePowerIMU=0;%IMU noisePower

ModelParam_noiseUpperGPS=0.5;  %GPS noise upper limit (unit:m)
ModelParam_noiseGPSSampTime=0.02;%GPS Sample time (5Hz)

ModelParam_noiseUpperBaro=0.1; %barometer noise upper limit (unit: m)
ModelParam_noiseBaroSampTime=0.02;%barometer noise sample time
ModelParam_noiseBaroCoupleWithSpeed=0;% barometer disturbance factor caused by moving forward

ModelParam_noiseUpperWindBodyRatio=0;% wind distrubance amplitude scale factor
ModelParam_noiseWindSampTime=0.001;


ModelParam_envAirDensity = 1.225;    %ideal air density (not used)
ModelParam_envDiffPressure = 0; % Differential pressure (airspeed) in millibar
ModelParam_noiseTs = 0.001;



%Failt Injection Test
ModelFailEnable = boolean(0); %is enabling failt injection test

%Battery fault simulation info.


%Payload failure injection


%wind disturbance Failure


