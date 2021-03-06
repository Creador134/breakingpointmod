/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

#define private		0
#define protected		1
#define public		2

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

class CfgPatches {
	class breakingpoint_thirsk {
		units[] = {"Thirsk","ThirskW","Land_trafficSign_40","Land_trafficSign_80","Land_trafficSing_militaryArea","Land_trafficSign_moose","Land_trafficSign_rocks","Land_trafficSign_turnL","Land_trafficSign_turnR","Land_trafficSign_reflectorStick","Land_miscSigns_minesStick"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"CAData", "CABuildings", "CAMisc", "CABuildings2", "CARoads2","A3_Data_F"};
	};
};

class CfgSounds
{
	class snowstorm
	{
		name = "Snowstorm";
		sound[] = {"\RHNET\Thirsk5\sounds\snowstorm.ogg", db+0, 1.0};
		titles[] = {0, "snowstorm"};
	};

	class snowstorm_silent
	{
		name = "Snowstorm";
		sound[] = {"\RHNET\Thirsk5\sounds\snowstorm.ogg", db-20, 1.0};
		titles[] = {0, "snowstorm_silent"};
	};
};

class CfgVehicleClasses
{
	class ThirskIsland { displayName = "Thirsk Island"; };
};

class CfgVehicles {
	class All {};
	class Logic : All {};
	class Static : All {};
	
	class Land_trafficSignsBase : Static {
		armor = 150; // cannot be destroyed by bullets
		animated = false; // not animated
		mapSize = 0.1;
		icon = "iconStaticObject";
		scope = 2; // 2 = public (can be seen from editor)
		           // 1 = private
		accuracy = 0.2; // accuracy -> recognize type
		placement = "vertical";

		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;

		destrType = "destructtree"; // will fall like a tree

		class DestructionEffects {
			class DestroyPhase1 {	// wtf is happening here
				simulation = "destroy";
				type = "DelayedDestruction";
				lifeTime = 2.5;
				position = "";
				intensity = 1;
				interval = 1;
			};
		};
	};
	
	class Land_trafficSign_40 : Land_trafficSignsBase { // uses defaults from class trafficsignbase
		model = "\RHNET\Thirsk6\hum_trafficSigns_40.p3d"; // model location
		vehicleClass = "ThirskIsland"; // belongs to addon..
		displayName = "Speedlimit Sign 40km/h"; // object name
	};

	class Land_trafficSign_80 : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_80.p3d";
		vehicleClass = "ThirskIsland";
		displayName = "Speedlimit Sign 80km/h";
	};

	class Land_trafficSign_militaryArea : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_militaryArea.p3d";
		vehicleClass = "ThirskIsland";
		displayName = "Military Area Sign";
	};

	class Land_trafficSign_moose : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_moose.p3d";
		vehicleClass = "ThirskIsland";
		displayName = "Moose Warning Sign";
	};

	class Land_trafficSign_rocks : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_rocks.p3d";
		vehicleClass = "ThirskIsland";
		displayName = "Falling Rocks Sign";
	};

	class Land_trafficSign_turnL : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_turnL.p3d";
		vehicleClass = "ThirskIsland";
		displayName = "S-turn Left Sign";
	};

	class Land_trafficSign_turnR : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_turnR.p3d";
		vehicleClass = "ThirskIsland";
		displayName = "S-turn Right Sign";
	};

	class Land_trafficSign_reflectorStick : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_trafficSigns_reflectorStick.p3d";
		vehicleClass = "ThirskIsland";
		displayName = "Roadway Marker";

		armor = 5; // can be shot down
		destrType = "destructtree"; // will fall like a tree
		class DestructionEffects;
	};

	class Land_miscSigns_minesStick : Land_trafficSignsBase {
		model = "\RHNET\Thirsk6\hum_miscSigns_minesStick.p3d";
		vehicleClass = "ThirskIsland";
		displayName = "Mines Sign on Stick";

		armor = 10; // can be shot down
		destrType = "destructtree"; // will fall like a tree
		class DestructionEffects;
	};

	class ThingEffect;	// External class reference
	class ThingEffectLight;	// External class reference
	class ThingEffectFeather;	// External class reference
	
	class FXCrWindLeaf1 : ThingEffectLight {
		scope = protected;
		model = "\ca\plants2\clutter\cr_leaf.p3d";
		displayName = "Internal: FxCrWindLeaf1";
		airFriction2[] = {2, 2, 8};
		airFriction1[] = {1, 1, 4};
		airFriction0[] = {0.3, 0.3, 0.1};
		airRotation = 0.35;
		minHeight = 0.3;
		avgHeight = 5.5;
		maxHeight = 10.0;
	};
	
	class FXCrWindLeaf2 : FXCrWindLeaf1 {
		model = "\ca\plants2\clutter\cr_leaf2.p3d";
		displayName = "Internal: FxCrWindLeaf2";
	};
	
	class FXCrWindLeaf3 : FXCrWindLeaf1 {
		model = "\ca\plants2\clutter\cr_leaf3.p3d";
		displayName = "Internal: FxCrWindLeaf3";
	};
	
	class Building: Static {};
	class NonStrategic: Building {};
	class Fire: NonStrategic {};
};

class CfgWorlds {
	class DefaultWorld {
		class Weather;	// External class reference
	};
	
	class CAWorld : DefaultWorld {
		class Grid {};
		class DayLightingBrightAlmost;	// External class reference
		class DayLightingRainy;	// External class reference
		class DefaultClutter;	// External class reference
		
		class Weather : Weather {
			class Lighting;	// External class reference
		};
	};
	class DefaultLighting;	// External class reference
	
	class Thirsk : CAWorld {
		dynLightMinBrightnessAmbientCoef = 0.5;
		dynLightMinBrightnessAbsolute = 0.05;	
		access = 3;
		worldId = 4;
		cutscenes[] = {};
		author = "Raunhofer.net (Ported By Breaking Point)";
		description = "Thirsk Summer";
		icon = "";
		worldName = "\RHNET\Thirsk2\Thirsk.wrp";
		pictureMap = "\RHNET\Thirsk\data\ThirskSummer.jpg";			
		plateFormat = "ML$ - #####";
		plateLetters = ABCDEGHIKLMNOPRSTVXZ;
		longitude = 26;	// positive is east
		latitude = -68;	// positive is south
		loadingTexts[]=
		{
			"Thirsk Summer was originally created by Raunhofer and then ported to Arma 3 by Breaking Point.",
		};
		
		class ReplaceObjects {};


		class Grid : Grid {
			offsetX = 0;
			offsetY = 0;
			
			class Zoom1 {
				zoomMax = 0.15;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = 100;
			};
			
			class Zoom2 {
				zoomMax = 0.85;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = 1000;
			};
			
			class Zoom3 {
				zoomMax = 1e+030;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000;
				stepY = 10000;
			};
		};
		startTime = 08:00;
		startDate = 1/7/2014;
		startWeather = 0.25;
		startFog = 0.15;
		forecastWeather = 0.15;
		forecastFog = 0.0;
		centerPosition[] = {1380, 2030, 300};
		seagullPos[] = {2626, 150, 1865};
		ilsPosition[] = {1106, 3236};
		ilsDirection[] = {-0.9205, 0.080, 0.3907};
		ilsTaxiIn[] = {1453, 3050, 1124, 3190, 1116, 3207, 1134, 3219, 1151, 3216};
		ilsTaxiOff[] = {1643, 3008, 1667, 2979, 1637, 2972, 1585, 2993};
		drawTaxiway = 1;
		
		class SecondaryAirports {
	        class Thirsk_Abafield {
				ilsPosition[] = {596, 565};
				ilsDirection[] = {-1.0000, 0.080, 0.0000};
				ilsTaxiIn[] = {681.975, 525.337, 638.61, 526.458, 616.927, 538.982, 612.254, 556.926, 630.199, 564.029};
				ilsTaxiOff[] = {1046.05, 565.157, 1071.41, 557.501, 1068.54, 534.054, 1033.61, 529.27, 822.112, 529.27};
				drawTaxiway = 1;
			};
		};
		
		class Sounds {
			sounds[] = {};
		};
		
		class Animation {
			vehicles[] = {};
		};
		
		class Lighting: DefaultLighting
		{
			groundReflection[] = {0.132,0.133,0.122};
			moonObjectColorFull[] = {550,500,450,1.0};
			moonHaloObjectColorFull[] = {20,20,20,0.5};
			moonsetObjectColor[] = {275,250,225,1.0};
			moonsetHaloObjectColor[] = {10,10,10,0.25};
			class ThunderBoltLight
			{
				diffuse[] = {2120,2170,8550};
				ambient[] = {0.001,0.001,0.001};
				intensity = 120000;
				class Attenuation
				{
					start = 0.0;
					constant = 0.0;
					linear = 0.0;
					quadratic = 1.0;
				};
			};
			starEmissivity = 60.0;
		};
		class DayLightingBrightAlmost: DayLightingBrightAlmost
		{
			deepNight[] = {-15,{ 0.005,0.01,0.01 },{ 0.0,0.002,0.003 },{ 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },{ 0.0,0.002,0.003 },{ 0.0,0.002,0.003 },0};
			fullNight[] = {-5,{ 0.182,0.213,0.25 },{ 0.05,0.111,0.221 },{ 0.04,0.034,0.004 },{ 0.039,0.049,0.072 },{ 0.082,0.128,0.185 },{ 0.283,0.35,0.431 },0};
			sunMoon[] = {-3.75,{ 0.377,0.441,0.518 },{ 0.103,0.227,0.453 },{ 0.04,0.034,0.004 },{ 0.039,0.049,0.072 },{ 0.174,0.274,0.395 },{ 0.582,0.72,0.887 },0.5};
			earlySun[] = {-2.5,{ 0.675,0.69,0.784 },{ 0.22,0.322,0.471 },{ 0.04,0.034,0.004 },{ 0.039,0.049,0.072 },{ 0.424,0.549,0.745 },{ 0.698,0.753,0.894 },1};
			sunrise[] = {0,{ 0.675,0.69,0.784 },{ 0.478,0.51,0.659 },{ 0.2,0.19,0.07 },{ 0.124,0.161,0.236 },{ { 0.847,0.855,0.965 },0.2 },{ { 0.933,0.949,0.996 },2 },1};
			earlyMorning[] = {3,{ { 0.844,0.61,0.469 },0.8 },{ 0.424,0.557,0.651 },{ { 1,0.45,0.2 },1 },{ 0.12,0.26,0.38 },{ { 0.428,0.579,0.743 },2 },{ { 0.844,0.61,0.469 },2.7 },1};
			midMorning[] = {8,{ { 0.822,0.75,0.646 },3.8 },{ { 0.383,0.58,0.858 },1.3 },{ { 1.3,0.9,0.61 },2.8 },{ { 0.12,0.18,0.28 },0.5 },{ { 0.322,0.478,0.675 },3.5 },{ { 1.0,0.929,0.815 },4.7 },1};
			morning[] = {16,{ { 1,0.95,0.91 },12.2 },{ { 0.12,0.18,0.28 },9.2 },{ { 1,0.95,0.91 },11.2 },{ { 0.12,0.18,0.28 },8.5 },{ { 0.14,0.18,0.24 },11.0 },{ { 0.5,0.6,0.9 },13.2 },1};
			noon[] = {45,{ { 0.98,0.94,0.94 },13.8 },{ { 0.2,0.27,0.35 },10.8 },{ { 0.98,0.94,0.94 },13.8 },{ { 0.2,0.27,0.35 },10.8 },{ { 0.5,0.64,1.0 },12.0 },{ { 0.5,0.5,0.5 },14.8 },1,0.5,0.4,0.5,0.4};
		};
		class DayLightingRainy: DayLightingRainy
		{
			deepNight[] = {-15,{ 0.005,0.01,0.01 },{ 0.0,0.002,0.003 },{ 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },{ 0.0,0.002,0.003 },{ 0.0,0.002,0.003 },0};
			fullNight[] = {-5,{ 0.023,0.023,0.023 },{ 0.02,0.02,0.02 },{ 0.023,0.023,0.023 },{ 0.02,0.02,0.02 },{ 0.01,0.01,0.02 },{ 0.08,0.06,0.06 },0};
			sunMoon[] = {-3.75,{ 0.04,0.04,0.05 },{ 0.04,0.04,0.05 },{ 0.04,0.04,0.05 },{ 0.04,0.04,0.05 },{ 0.04,0.035,0.04 },{ 0.11,0.08,0.09 },0.5};
			earlySun[] = {-2.5,{ 0.0689,0.0689,0.0804 },{ 0.06,0.06,0.07 },{ 0.0689,0.0689,0.0804 },{ 0.06,0.06,0.07 },{ 0.08,0.07,0.08 },{ 0.14,0.1,0.12 },0.5};
			earlyMorning[] = {3,{ { 1,1,1 },"(-4)+3.95" },{ { 1,1,1 },"(-4)+3.0" },{ { 1,1,1 },"(-4)+3.95" },{ { 1,1,1 },"(-4)+3.0" },{ { 1,1,1 },"(-4)+4" },{ { 1,1,1 },"(-4)+5.5" },1};
			morning[] = {16,{ { 1,1,1 },"(-4)+5.7" },{ { 1,1,1 },"(-4)+4.5" },{ { 1,1,1 },"(-4)+5.7" },{ { 1,1,1 },"(-4)+4.5" },{ { 1,1,1 },"(-4)+7" },{ { 1,1,1 },"(-4)+8" },1};
			lateMorning[] = {25,{ { 1,1,1 },"(-4)+10.45" },{ { 1,1,1 },"(-4)+9.75" },{ { 1,1,1 },"(-4)+10.45" },{ { 1,1,1 },"(-4)+9.75" },{ { 1,1,1 },"(-4)+12" },{ { 1,1,1 },"(-4)+12.75" },1};
			noon[] = {45,{ { 1,1,1 },10.0 },{ { 1,1,1 },9.0 },{ { 1,1,1 },9.0 },{ { 1,1,1 },8.0 },{ { 0.5,0.64,1 },12.0 },{ { 0.5,0.5,0.5 },14.8 },1};
		};
		
		class Weather : Weather {
			class Lighting : Lighting {
				class BrightAlmost : DayLightingBrightAlmost {
					overcast = 0;
				};

				class Rainy : DayLightingRainy {
					overcast = 1.0;
				};
			};
		};
		clutterGrid = 1.0;
		clutterDist = 200;
		noDetailDist = 40;
		fullDetailDist = 15;
		midDetailTexture = "RHNET\Thirsk\data\thirmiddle.paa";
		minTreesInForestSquare = 4;
		minRocksInRockSquare = 2;
		
		class clutter {
			class GrassTall : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassTall.p3d";
				affectedByWind = 0.4;
				swLighting = 1;
				scaleMin = 0.7;
				scaleMax = 1.0;
			};
			
			class StubbleClutter : DefaultClutter {
				model = "ca\plants2\clutter\c_stubble.p3d";
				affectedByWind = 0.1;
				swLighting = 1;
				scaleMin = 0.9;
				scaleMax = 1.1;
			};
			
			class AutumnFlowers : DefaultClutter {
				model = "ca\plants2\clutter\c_autumn_flowers.p3d";
				affectedByWind = 0.4;
				swLighting = 1;
				scaleMin = 0.7;
				scaleMax = 1.0;
			};
			
			class GrassBunch : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassBunch.p3d";
				affectedByWind = 0.35;
				swLighting = 1;
				scaleMin = 0.6;
				scaleMax = 1.0;
			};
			
			class GrassCrooked : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassCrooked.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.7;
				scaleMax = 1.4;
			};
			
			class GrassCrookedGreen : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassCrookedGreen.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.9;
				scaleMax = 1.3;
			};
			
			class GrassCrookedForest : DefaultClutter {
				model = "ca\plants2\clutter\c_GrassCrookedForest.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.4;
			};
			
			class WeedDead : DefaultClutter {
				model = "ca\plants2\clutter\c_WeedDead.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.75;
				scaleMax = 1.1;
			};
			
			class WeedDeadSmall : DefaultClutter {
				model = "ca\plants2\clutter\c_WeedDead2.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.75;
				scaleMax = 0.9;
			};
			
			class HeatherBrush : DefaultClutter {
				model = "ca\plants2\clutter\c_caluna.p3d";
				affectedByWind = 0.15;
				swLighting = 1;
				scaleMin = 0.9;
				scaleMax = 1.8;
				surfaceColor[] = {0.53, 0.5, 0.37, 1};
			};
			
			class WeedSedge : DefaultClutter {
				model = "ca\plants2\clutter\c_weed3.p3d";
				affectedByWind = 0.2;
				swLighting = 1;
				scaleMin = 0.5;
				scaleMax = 0.85;
			};
			
			class WeedTall : DefaultClutter {
				model = "ca\plants2\clutter\c_weed2.p3d";
				affectedByWind = 0.3;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.1;
			};
			
			class BlueBerry : DefaultClutter {
				model = "ca\plants2\clutter\c_BlueBerry.p3d";
				affectedByWind = 0.05;
				swLighting = 1;
				scaleMin = 0.85;
				scaleMax = 1.4;
			};
			
			class RaspBerry : DefaultClutter {
				model = "ca\plants2\clutter\c_raspBerry.p3d";
				affectedByWind = 0;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			
			class FernAutumn : DefaultClutter {
				model = "ca\plants2\clutter\c_fern.p3d";
				affectedByWind = 0.1;
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			
			class FernAutumnTall : DefaultClutter {
				model = "ca\plants2\clutter\c_fernTall.p3d";
				affectedByWind = 0.15;
				scaleMin = 0.75;
				scaleMax = 1.25;
			};
			
			class SmallPicea : DefaultClutter {
				model = "ca\plants2\clutter\c_picea.p3d";
				affectedByWind = 0.05;
				scaleMin = 0.60;
				scaleMax = 1.30;
			};
			
			class PlantWideLeaf : DefaultClutter {
				model = "ca\plants2\clutter\c_WideLeafPlant.p3d";
				affectedByWind = 0.1;
				scaleMin = 1.0;
				scaleMax = 1.0;
			};
			
			class MushroomsHorcak : DefaultClutter {
				model = "ca\plants2\clutter\c_MushroomHorcak.p3d";
				affectedByWind = 0;
				scaleMin = 0.85;
				scaleMax = 1.25;
			};
			
			class MushroomsPrasivka : MushroomsHorcak {
				model = "ca\plants2\clutter\c_MushroomPrasivky.p3d";
			};
			
			class MushroomsBabka : MushroomsHorcak {
				model = "ca\plants2\clutter\c_MushroomBabka.p3d";
			};
			
			class MushroomsMuchomurka : MushroomsHorcak {
				model = "ca\plants2\clutter\c_MushroomMuchomurka.p3d";
			};
		};
		
		class Subdivision {
			class Fractal {
				rougness = 5;
				maxRoad = 0.02;
				maxTrack = 0.5;
				maxSlopeFactor = 0.05;
			};
			
			class WhiteNoise {
				rougness = 2;
				maxRoad = 0.01;
				maxTrack = 0.05;
				maxSlopeFactor = 0.0025;
			};
			minY = 0.0;
			minSlope = 0.02;
		};
		
		class Ambient {
			class Mammals {
				radius = 200;
				cost = "(1 + forest + trees) * (0.5 + (0.5 * night)) * (1 - sea) * (1 - houses)";
				
				class Species {
					class Rabbit {
						probability = 0.2;
						cost = 1;
					};
				};
			};
			
			class BigBirds {
				radius = 300;
				cost = "((1 + forest + trees) - ((2 * rain)) - houses) * (1 - night) * (1 - sea)";
				
				class Species {
					class Hawk {
						probability = 0.2;
						cost = 1;
					};
				};
			};
			
			class Birds {
				radius = 170;
				cost = "(1 - night) * ((1 + (3 * sea)) - (2 * rain))";
				
				class Species {
					class Crow {
						probability = 0.2;
						cost = 1;
					};
				};
			};
			
			class BigInsects {
				radius = 20;
				cost = "(5 - (2 * houses)) * (1 - night) * (1 - rain) * (1 - sea) * (1 - windy)";
				
				class Species {
					class DragonFly {
						probability = "0.6 - (meadow * 0.5) + (forest * 0.4)";
						cost = 1;
					};
					
					class ButterFly {
						probability = "0.4 + (meadow * 0.5) - (forest * 0.4)";
						cost = 1;
					};
				};
			};
			
			class BigInsectsAquatic {
				radius = 20;
				cost = "(3 * sea) * (1 - night) * (1 - rain) * (1 - windy)";
				
				class Species {
					class DragonFly {
						probability = 1;
						cost = 1;
					};
				};
			};
			
			class SmallInsects {
				radius = 3;
				cost = "(12 - 8 * hills) * (1 - night) * (1 - rain) * (1 - sea) * (1 - windy)";
				
				class Species {
					class HouseFly {
						probability = "deadBody + (1 - deadBody) * (0.5 - forest * 0.1 - meadow * 0.2)";
						cost = 1;
					};
					
					class HoneyBee {
						probability = "(1 - deadBody) * (0.5 - forest * 0.1 + meadow * 0.2)";
						cost = 1;
					};
					
					class Mosquito {
						probability = "(1 - deadBody) * (0.2 * forest)";
						cost = 1;
					};
				};
			};
			
			class NightInsects {
				radius = 3;
				cost = "(9 - 8 * hills) * night * (1 - rain) * (1 - sea) * (1 - windy)";
				
				class Species {
					class Mosquito {
						probability = 1;
						cost = 1;
					};
				};
			};
			
			class WindClutter {
				radius = 10;
				cost = "((20 - 5 * rain) * (3 * (windy factor [0.2, 0.5]))) * (1 - sea)";
				
				class Species {
					class FxWindGrass1 {
						probability = "0.4 - 0.2 * hills - 0.2 * trees";
						cost = 1;
					};
					
					class FxWindGrass2 {
						probability = "0.4 - 0.2 * hills - 0.2 * trees";
						cost = 1;
					};
					
					class FxWindRock1 {
						probability = "0.4 * hills";
						cost = 1;
					};
					
					class FxCrWindLeaf1 {
						probability = "0.2 * trees";
						cost = 1;
					};
					
					class FxCrWindLeaf2 {
						probability = "0.1 * trees + 0.2";
						cost = 1;
					};
					
					class FxCrWindLeaf3 {
						probability = "0.1 * trees";
						cost = 1;
					};
				};
			};
			
			class NoWindClutter {
				radius = 15;
				cost = 8;
				
				class Species {
					class FxWindPollen1 {
						probability = 1;
						cost = 1;
					};
					
					class FxCrWindLeaf1 {
						probability = "0.2 * trees";
						cost = 1;
					};
					
					class FxCrWindLeaf2 {
						probability = "0.1 * trees + 0.2";
						cost = 1;
					};
					
					class FxCrWindLeaf3 {
						probability = "0.1 * trees";
						cost = 1;
					};
				};
			};
		};
		
	class Names {
			class Thirsk_isl001 {
				name = "Thirsk";
				position[] = {1408, 3075};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl002 {
				name = "Taimenlahti";
				position[] = {3366, 1341};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl003 {
				name = "Itälahti";
				position[] = {4390, 2087};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl004 {
				name = "";
				position[] = {3648.75, 3940};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl005 {
				name = "";
				position[] = {1445, 3560};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl006 {
				name = "";
				position[] = {2610, 3638};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl007 {
				name = "";
				position[] = {811.25, 3388.75};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl008 {
				name = "";
				position[] = {3284, 2722};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class Thirsk_isl011 {
				name = "Siipilahti";
				position[] = {2098, 3093};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl012 {
				name = "гибель";
				position[] = {2879.17, 3243.96};
				type = "NameVillage";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class Thirsk_isl013 {
				name = "Eteläpato";
				position[] = {4078.99, 1662.73};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl014 {
				name = "Sudensuoja";
				position[] = {4131, 2670};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl015 {
				name = "Karhunhammas";
				position[] = {4026, 1206};
				type = "NameCity";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl016 {
				name = "Mansikkaniemi";
				position[] = {2286, 4658};
				type = "Name";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl017 {
				name = "Mustikkasaari";
				position[] = {3530, 4749};
				type = "NameCity";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl018 {
				name = "THIRSK";
				position[] = {1320.53, 2039.15};
				type = "NameCityCapital";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl019 {
				name = "Kuikin portti";
				position[] = {4006.25, 620.00};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl020 {
				name = "Vasarakarikko";
				position[] = {4721.48, 4816.55};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl021 {
				name = "Valliallas";
				position[] = {3700.77, 1641.78};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl022 {
				name = "";
				position[] = {3540.00, 675.00};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class Thirsk_isl023 {
				name = "Jafarinin kivi";
				position[] = {3159.42, 3627.25};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl024 {
				name = "Radiomäki";
				position[] = {4352.56, 1370.22};
				type = "Hill";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl025 {
				name = "Ilmarinen";
				position[] = {726.412, 562.765};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl026 {
				name = "";
				position[] = {4336, 1325};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl027 {
				name = "Vanha paloasema";
				position[] = {3972, 1386};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl028 {
				name = "Pieni Karhunhammas";
				position[] = {3510, 757};
				type = "Name";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl029 {
				name = "Potoskanlahti";
				position[] = {2019, 4352};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl030 {
				name = "Oikurin kallio";
				position[] = {2009, 4253};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl031 {
				name = "Malisen kallio";
				position[] = {2121, 3291};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl032 {
				name = "Pöyrynmäki";
				position[] = {3926, 3644};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl033 {
				name = "Ristikangas";
				position[] = {2556, 3829};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl034 {
				name = "";
				position[] = {2602, 3489};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl035 {
				name = "Välimetsä";
				position[] = {1392, 3583};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl036 {
				name = "";
				position[] = {1136, 4791};
				type = "VegetationBroadleaf";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl037 {
				name = "";
				position[] = {1213, 4474};
				type = "VegetationBroadleaf";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl038 {
				name = "";
				position[] = {2370, 4517};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl039 {
				name = "Ruosterinne";
				position[] = {615, 3698};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl040 {
				name = "Rocknoil";
				position[] = {664, 2419};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl041 {
				name = "";
				position[] = {964, 1978};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl042 {
				name = "Ykspihlaja";
				position[] = {1040, 4790};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl043 {
				name = "Hirvenpää";
				position[] = {2038, 1080};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl044 {
				name = "Kivipää";
				position[] = {454, 892};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl045 {
				name = "";
				position[] = {2915, 1810};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl046 {
				name = "Tuulensuoja";
				position[] = {1350, 4039};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl047 {
				name = "Etelälahti";
				position[] = {1386, 868};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl048 {
				name = "Elimyssalo";
				position[] = {3385, 3497};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class Thirsk_isl049 {
				name = "Ylämylly";
				position[] = {2732, 2099};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};
		};
	};
	
	class ThirskW : CAWorld {
		dynLightMinBrightnessAmbientCoef = 0.5;
		dynLightMinBrightnessAbsolute = 0.05;		
		access = 3;
		worldId = 4;
		cutscenes[] = {};
		author = "Raunhofer.net (Ported By Breaking Point)";		
		description = "Thirsk Winter";
		icon = "";
		worldName = "\RHNET\Thirsk4\ThirskW.wrp";
		pictureMap = "\RHNET\Thirsk\data\ThirskWinter.jpg";		
		plateFormat = "ML$ - #####";
		plateLetters = ABCDEGHIKLMNOPRSTVXZ;
		longitude = 26;	// positive is east
		latitude = -68;	// positive is south
		loadingTexts[]=		
		{
			"Thirsk Winter was originally created by Raunhofer and then ported to Arma 3 by Breaking Point.",
		};
		class ReplaceObjects {};


		class Grid : Grid {
			offsetX = 0;
			offsetY = 0;
			
			class Zoom1 {
				zoomMax = 0.15;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = 100;
			};
			
			class Zoom2 {
				zoomMax = 0.85;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = 1000;
			};
			
			class Zoom3 {
				zoomMax = 1e+030;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000;
				stepY = 10000;
			};
		};
		startTime = 11:00;
		startDate = 16/3/1991;
		startWeather = 0.1;
		startFog = 0.2;
		forecastWeather = 0.2;
		forecastFog = 0.2;
		centerPosition[] = {1380, 2030, 300};
		seagullPos[] = {2626, 150, 1865};
		ilsPosition[] = {1106, 3236};
		ilsDirection[] = {-0.9205, 0.080, 0.3907};
		ilsTaxiIn[] = {1453, 3050, 1124, 3190, 1116, 3207, 1134, 3219, 1151, 3216};
		ilsTaxiOff[] = {1643, 3008, 1667, 2979, 1637, 2972, 1585, 2993};
		drawTaxiway = 1;
		
		class SecondaryAirports {

	        class Thirsk_Abafield {
                                ilsPosition[] = {596, 565};
                                ilsDirection[] = {-1.0000, 0.080, 0.0000};
                                ilsTaxiIn[] = {681.975, 525.337, 638.61, 526.458, 616.927, 538.982, 612.254, 556.926, 630.199, 564.029};
                                ilsTaxiOff[] = {1046.05, 565.157, 1071.41, 557.501, 1068.54, 534.054, 1033.61, 529.27, 822.112, 529.27};
                                drawTaxiway = 1;
                        };

		};
		
		class Sounds {
			sounds[] = {};
		};
		
		class Animation {
			vehicles[] = {};
		};
		
		class Lighting: DefaultLighting
		{
			groundReflection[] = {0.132,0.133,0.122};
			moonObjectColorFull[] = {550,500,450,1.0};
			moonHaloObjectColorFull[] = {20,20,20,0.5};
			moonsetObjectColor[] = {275,250,225,1.0};
			moonsetHaloObjectColor[] = {10,10,10,0.25};
			class ThunderBoltLight
			{
				diffuse[] = {2120,2170,8550};
				ambient[] = {0.001,0.001,0.001};
				intensity = 120000;
				class Attenuation
				{
					start = 0.0;
					constant = 0.0;
					linear = 0.0;
					quadratic = 1.0;
				};
			};
			starEmissivity = 60.0;
		};
		class DayLightingBrightAlmost: DayLightingBrightAlmost
		{
			deepNight[] = {-15,{ 0.005,0.01,0.01 },{ 0.0,0.002,0.003 },{ 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },{ 0.0,0.002,0.003 },{ 0.0,0.002,0.003 },0};
			fullNight[] = {-5,{ 0.182,0.213,0.25 },{ 0.05,0.111,0.221 },{ 0.04,0.034,0.004 },{ 0.039,0.049,0.072 },{ 0.082,0.128,0.185 },{ 0.283,0.35,0.431 },0};
			sunMoon[] = {-3.75,{ 0.377,0.441,0.518 },{ 0.103,0.227,0.453 },{ 0.04,0.034,0.004 },{ 0.039,0.049,0.072 },{ 0.174,0.274,0.395 },{ 0.582,0.72,0.887 },0.5};
			earlySun[] = {-2.5,{ 0.675,0.69,0.784 },{ 0.22,0.322,0.471 },{ 0.04,0.034,0.004 },{ 0.039,0.049,0.072 },{ 0.424,0.549,0.745 },{ 0.698,0.753,0.894 },1};
			sunrise[] = {0,{ 0.675,0.69,0.784 },{ 0.478,0.51,0.659 },{ 0.2,0.19,0.07 },{ 0.124,0.161,0.236 },{ { 0.847,0.855,0.965 },0.2 },{ { 0.933,0.949,0.996 },2 },1};
			earlyMorning[] = {3,{ { 0.844,0.61,0.469 },0.8 },{ 0.424,0.557,0.651 },{ { 1,0.45,0.2 },1 },{ 0.12,0.26,0.38 },{ { 0.428,0.579,0.743 },2 },{ { 0.844,0.61,0.469 },2.7 },1};
			midMorning[] = {8,{ { 0.822,0.75,0.646 },3.8 },{ { 0.383,0.58,0.858 },1.3 },{ { 1.3,0.9,0.61 },2.8 },{ { 0.12,0.18,0.28 },0.5 },{ { 0.322,0.478,0.675 },3.5 },{ { 1.0,0.929,0.815 },4.7 },1};
			morning[] = {16,{ { 1,0.95,0.91 },12.2 },{ { 0.12,0.18,0.28 },9.2 },{ { 1,0.95,0.91 },11.2 },{ { 0.12,0.18,0.28 },8.5 },{ { 0.14,0.18,0.24 },11.0 },{ { 0.5,0.6,0.9 },13.2 },1};
			noon[] = {45,{ { 0.98,0.94,0.94 },13.8 },{ { 0.2,0.27,0.35 },10.8 },{ { 0.98,0.94,0.94 },13.8 },{ { 0.2,0.27,0.35 },10.8 },{ { 0.5,0.64,1.0 },12.0 },{ { 0.5,0.5,0.5 },14.8 },1,0.5,0.4,0.5,0.4};
		};
		class DayLightingRainy: DayLightingRainy
		{
			deepNight[] = {-15,{ 0.005,0.01,0.01 },{ 0.0,0.002,0.003 },{ 0.0,0.0,0.0 },{ 0.0,0.0,0.0 },{ 0.0,0.002,0.003 },{ 0.0,0.002,0.003 },0};
			fullNight[] = {-5,{ 0.023,0.023,0.023 },{ 0.02,0.02,0.02 },{ 0.023,0.023,0.023 },{ 0.02,0.02,0.02 },{ 0.01,0.01,0.02 },{ 0.08,0.06,0.06 },0};
			sunMoon[] = {-3.75,{ 0.04,0.04,0.05 },{ 0.04,0.04,0.05 },{ 0.04,0.04,0.05 },{ 0.04,0.04,0.05 },{ 0.04,0.035,0.04 },{ 0.11,0.08,0.09 },0.5};
			earlySun[] = {-2.5,{ 0.0689,0.0689,0.0804 },{ 0.06,0.06,0.07 },{ 0.0689,0.0689,0.0804 },{ 0.06,0.06,0.07 },{ 0.08,0.07,0.08 },{ 0.14,0.1,0.12 },0.5};
			earlyMorning[] = {3,{ { 1,1,1 },"(-4)+3.95" },{ { 1,1,1 },"(-4)+3.0" },{ { 1,1,1 },"(-4)+3.95" },{ { 1,1,1 },"(-4)+3.0" },{ { 1,1,1 },"(-4)+4" },{ { 1,1,1 },"(-4)+5.5" },1};
			morning[] = {16,{ { 1,1,1 },"(-4)+5.7" },{ { 1,1,1 },"(-4)+4.5" },{ { 1,1,1 },"(-4)+5.7" },{ { 1,1,1 },"(-4)+4.5" },{ { 1,1,1 },"(-4)+7" },{ { 1,1,1 },"(-4)+8" },1};
			lateMorning[] = {25,{ { 1,1,1 },"(-4)+10.45" },{ { 1,1,1 },"(-4)+9.75" },{ { 1,1,1 },"(-4)+10.45" },{ { 1,1,1 },"(-4)+9.75" },{ { 1,1,1 },"(-4)+12" },{ { 1,1,1 },"(-4)+12.75" },1};
			noon[] = {45,{ { 1,1,1 },10.0 },{ { 1,1,1 },9.0 },{ { 1,1,1 },9.0 },{ { 1,1,1 },8.0 },{ { 0.5,0.64,1 },12.0 },{ { 0.5,0.5,0.5 },14.8 },1};
		};
		
		class Weather : Weather {
			class Lighting : Lighting {
				class BrightAlmost : DayLightingBrightAlmost {
					overcast = 0;
				};

				class Rainy : DayLightingRainy {
					overcast = 1.0;
				};
			};
		};
		clutterGrid = 1.0;
		clutterDist = 200;
		noDetailDist = 40;
		fullDetailDist = 15;
		midDetailTexture = "RHNET\Thirsk3\data\thir_middle_mco.paa";
		minTreesInForestSquare = 4;
		minRocksInRockSquare = 2;
		
		class clutter {
			class RaspSnow : DefaultClutter {
				model = "RHNET\Thirsk5\mdl\cl\wraspBerry.p3d";
				affectedByWind = 0;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			
			class BlueSnow : DefaultClutter {
				model = "RHNET\Thirsk5\mdl\cl\wblueBerry.p3d";
				affectedByWind = 0;
				swLighting = 1;
				scaleMin = 0.8;
				scaleMax = 1.2;
			};
			
			class FernSnow : DefaultClutter {
				model = "RHNET\Thirsk5\mdl\cl\wfern.p3d";
				affectedByWind = 0.1;
				scaleMin = 0.6;
				scaleMax = 1.2;
			};
			
			class SnowPicea : DefaultClutter {
				model = "RHNET\Thirsk5\mdl\cl\wpicea.p3d";
				affectedByWind = 0.0;
				scaleMin = 0.6;
				scaleMax = 1.3;
			};
		};
		
		class Subdivision {
			class Fractal {
				rougness = 5;
				maxRoad = 0.02;
				maxTrack = 0.5;
				maxSlopeFactor = 0.05;
			};
			
			class WhiteNoise {
				rougness = 2;
				maxRoad = 0.01;
				maxTrack = 0.05;
				maxSlopeFactor = 0.0025;
			};
			minY = 0.0;
			minSlope = 0.02;
		};
		
		class Ambient {
			class Mammals {
				radius = 200;
				cost = "(1 + forest + trees) * (0.5 + (0.5 * night)) * (1 - sea) * (1 - houses)";
				
				class Species {
					class Rabbit {
						probability = 0.2;
						cost = 1;
					};
				};
			};
			
			class BigBirds {
				radius = 300;
				cost = "((1 + forest + trees) - ((2 * rain)) - houses) * (1 - night) * (1 - sea)";
				
				class Species {
					class Hawk {
						probability = 0.1;
						cost = 1;
					};
				};
			};
			
			class Birds {
				radius = 170;
				cost = "(1 - night) * ((1 + (3 * sea)) - (2 * rain))";
				
				class Species {
					class Crow {
						probability = 0.1;
						cost = 1;
					};
				};
			};
			
			
		};

	class Names {
			class WThirsk_isl001 {
				name = "Thirsk";
				position[] = {1408, 3075};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl002 {
				name = "Taimenlahti";
				position[] = {3366, 1341};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl003 {
				name = "Itälahti";
				position[] = {4390, 2087};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl004 {
				name = "";
				position[] = {3648.75, 3940};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl005 {
				name = "";
				position[] = {1445, 3560};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl006 {
				name = "";
				position[] = {2610, 3638};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl007 {
				name = "";
				position[] = {811.25, 3388.75};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl008 {
				name = "";
				position[] = {3284, 2722};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class WThirsk_isl011 {
				name = "Siipilahti";
				position[] = {2098, 3093};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl012 {
				name = "гибель";
				position[] = {2879.17, 3243.96};
				type = "NameVillage";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class WThirsk_isl013 {
				name = "Eteläpato";
				position[] = {4078.99, 1662.73};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl014 {
				name = "Sudensuoja";
				position[] = {4131, 2670};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl015 {
				name = "Karhunhammas";
				position[] = {4026, 1206};
				type = "NameCity";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl016 {
				name = "Mansikkaniemi";
				position[] = {2286, 4658};
				type = "Name";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl017 {
				name = "Mustikkasaari";
				position[] = {3530, 4749};
				type = "NameCity";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl018 {
				name = "THIRSK";
				position[] = {1320.53, 2039.15};
				type = "NameCityCapital";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl019 {
				name = "Kuikin portti";
				position[] = {4006.25, 620.00};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl020 {
				name = "Vasarakarikko";
				position[] = {4721.48, 4816.55};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl021 {
				name = "Valliallas";
				position[] = {3700.77, 1641.78};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl022 {
				name = "";
				position[] = {3540.00, 675.00};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};


			class WThirsk_isl023 {
				name = "Jafarinin kivi";
				position[] = {3159.42, 3627.25};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl024 {
				name = "Radiomäki";
				position[] = {4352.56, 1370.22};
				type = "Hill";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl025 {
				name = "Ilmarinen";
				position[] = {726.412, 562.765};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl026 {
				name = "";
				position[] = {4336, 1325};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl027 {
				name = "Vanha paloasema";
				position[] = {3972, 1386};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl028 {
				name = "Pieni Karhunhammas";
				position[] = {3510, 757};
				type = "Name";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl029 {
				name = "Potoskanlahti";
				position[] = {2019, 4352};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl030 {
				name = "Oikurin kallio";
				position[] = {2009, 4253};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl031 {
				name = "Malisen kallio";
				position[] = {2121, 3291};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl032 {
				name = "Pöyrynmäki";
				position[] = {3926, 3644};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl033 {
				name = "Ristikangas";
				position[] = {2556, 3829};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl034 {
				name = "";
				position[] = {2602, 3489};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl035 {
				name = "Välimetsä";
				position[] = {1392, 3583};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl036 {
				name = "";
				position[] = {1136, 4791};
				type = "VegetationBroadleaf";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl037 {
				name = "";
				position[] = {1213, 4474};
				type = "VegetationBroadleaf";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl038 {
				name = "";
				position[] = {2370, 4517};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl039 {
				name = "Ruosterinne";
				position[] = {615, 3698};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl040 {
				name = "Rocknoil";
				position[] = {664, 2419};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl041 {
				name = "";
				position[] = {964, 1978};
				type = "VegetationFir";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl042 {
				name = "Ykspihlaja";
				position[] = {1040, 4790};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl043 {
				name = "Hirvenpää";
				position[] = {2038, 1080};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl044 {
				name = "Kivipää";
				position[] = {454, 892};
				type = "RockArea";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl045 {
				name = "";
				position[] = {2915, 1810};
				type = "ViewPoint";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl046 {
				name = "Tuulensuoja";
				position[] = {1350, 4039};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl047 {
				name = "Etelälahti";
				position[] = {1386, 868};
				type = "NameMarine";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl048 {
				name = "Elimyssalo";
				position[] = {3385, 3497};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};

			class WThirsk_isl049 {
				name = "Ylämylly";
				position[] = {2732, 2099};
				type = "NameLocal";
				speech[] = {};
				radiusA = 100;
				radiusB = 100;
				angle = 0.0;
			};
		};
	};
};

class CfgWorldList {
	class Thirsk {};
	class ThirskW {};
};

class CfgSurfaces {
	class Default {};
	
	class Water {};
	
	class THgrass2 : Default {
		access = 2;
		files = "nurmi_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "THPnurmi";
		soundHit = "soft_ground";
	};

	class THgrass3 : Default {
		access = 2;
		files = "heinikko_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "grass";
		character = "THPNurmi2";
		soundHit = "soft_ground";
	};
	
	class THForest1 : Default {
		access = ReadOnly;
		files = "metsa_*";
		rough = 0.11;
		dust = 0.2;
		soundEnviron = "grass";
		character = "THMetsa";
		soundHit = "soft_ground";
	};
	
	class THForest2 : Default {
		access = ReadOnly;
		files = "metsa2_*";
		rough = 0.2;
		dust = 0.15;
		soundEnviron = "grass";
		character = "THMetsa2";
		soundHit = "soft_ground";
	};

	
	class THGrit1 : Default {
		access = ReadOnly;
		files = "kivi_*";
		rough = 0.1;
		dust = 0.25;
		soundEnviron = "gravel";
		character = "Empty";
		soundHit = "hard_ground";
	};

	class THBetoni1 : Default {
		access = ReadOnly;
		files = "betoni_*";
		rough = 0.1;
		dust = 0.01;
		soundEnviron = "gravel";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class THRock : Default {
		access = ReadOnly;
		files = "kivi2_*";
		rough = 0.2;
		dust = 0.07;
		soundEnviron = "snow";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class THTarmac : Default {
		access = ReadOnly;
		files = "hiekka_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "tarmac";
		character = "Empty";
		soundHit = "hard_ground";
	};

	class THgrasW2 : Default {
		access = 2;
		files = "wnurmi_*";
		rough = 0.11;
		dust = 0.1;
		soundEnviron = "snow";
		character = "THPnurmW";
		soundHit = "soft_ground";
	};
	
	class THForesW1 : Default {
		access = 2;
		files = "wmetsa_*";
		rough = 0.5;
		dust = 0;
		soundEnviron = "snow";
		character = "THMetsW";
		soundHit = "soft_ground";
	};
	
	class THForesW2 : Default {
		access = 2;
		files = "wmetsa2_*";
		rough = 0.2;
		dust = 0.15;
		soundEnviron = "snow";
		character = "THMetsW2";
		soundHit = "soft_ground";
	};
	
	class THGriW1 : Default {
		access = 2;
		files = "wbetoni_*";
		rough = 0.1;
		dust = 0;
		soundEnviron = "tarmac";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class THRocW : Default {
		access = 2;
		files = "wkivi2_*";
		rough = 0.2;
		dust = 0.07;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	
	class THTarmaW : Default {
		access = 2;
		files = "whiekka_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "snow";
		character = "Empty";
		soundHit = "hard_ground";
	};
};

class CfgSurfaceCharacters {
	class THNurmi {
		probability[] = {0.78, 0.1, 0.06, 0.01, 0.05};
		names[] = {"GrassCrookedGreen", "GrassCrooked", "AutumnFlowers", "WeedDead", "SmallPicea"};
	};
	
	class THPnurmi {
		probability[] = {0.005, 0.1, 0.1, 0.3, 0.05};
		names[] = {"AutumnFlowers", "GrassCrooked", "GrassBunch", "GrassCrookedGreen", "RaspBerry"};
	};

	
	class THPnurmi2 {
		probability[] = {0.79, 0.1, 0.1, 0.01};
		names[] = {"GrassCrookedGreen", "GrassCrooked", "AutumnFlowers", "WeedDead"};
	};
	
	class THMetsa {
		probability[] = {0.55, 0.05, 0.15, 0.001, 0.003, 0.01, 0.2, 0.1};
		names[] = {"BlueBerry", "FernAutumn", "GrassCrooked", "MushroomsHorcak", "MushroomsPrasivka", "SmallPicea", "RaspBerry", "AutumnFlowers"};
	};
	
	class THMetsa2 {
		probability[] = {0.5, 0.3, 0.01, 0.4, 0.005, 0.008, 0.004};
		names[] = {"BlueBerry", "FernAutumn", "SmallPicea", "GrassCrooked", "MushroomsPrasivka", "MushroomsBabka", "MushroomsMuchomurka"};
	};
	
	class THKanerva {
		probability[] = {0.15, 0.5, 0.3, 0.1};
		names[] = {"BlueBerry", "HeatherBrush", "GrassCrooked", "WeedSedge"};
	};
	
	class THSekalainen {
		probability[] = {0.9, 0.01, 0.01, 0.005, 0.2};
		names[] = {"StubbleClutter", "AutumnFlowers", "WeedDeadSmall", "WeedDead", "SmallPicea"};
	};
	
	class THNurmW {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THPnurmW {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THNurmW2 {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THPnurmW2 {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THMetsW {
		probability[] = {0.001};
		names[] = {"SnowPicea"};
	};
	
	class THMetsW2 {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THKanervW {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
	
	class THSekalaineW {
		probability[] = {0.05, 0.01, 0.2};
		names[] = {"FernSnow", "SnowPicea", "RaspSnow"};
	};
};
