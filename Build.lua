workspace "AutomataExplorer"
    architecture "x64"
    configurations {"Debug", "Release", "Distrobution"}
    startproject "AutomataExplorer"

    filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

    OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"
  
project "AutomataExplorer"
    kind "ConsoleApp"
    language "C++"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    files {"./src/**.cpp", "./src/**.h", "./Kyuubi/**.cpp", "./Kyuubi/**.h"}

    includedirs {
        "Kyuubi/**",
        "Kyuubi",
        "src",
        "src/**",
        "Scenes"
    }

    filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"

   filter { "system:windows", "configurations:Dist" }
       optimize "Full"

   filter { "system:windows", "configurations:Release or Dist", "kind:SharedLib" }
       linkoptions { "/OPT:REF" } -- link-time code optimization