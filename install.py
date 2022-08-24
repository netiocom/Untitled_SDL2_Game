from alive_progress import alive_bar
import os
import colorama
import time
from random import uniform
import webbrowser

colorama.Style.RESET_ALL

cpp_files = [
    "main.cpp",
    "RenderWindow.cpp",
    "Utils.cpp",
    "Vector2.cpp",
    "Entity.cpp",
    "Player.cpp",
    "Tile.cpp",
    "Tilemap.cpp",
    "Physics2D.cpp"
]
hpp_files = [
    "RenderWindow.hpp",
    "Utils.hpp",
    "Vector2.hpp",
    "Player.hpp",
    "Entity.hpp",
    "Tile.hpp",
    "Tilemap.hpp",
    "Physics2D.hpp"
]
asset_files = [
    "microsoft.png"
]

SDL2_Files = [
    "SDL.h",
    "SDL_vulkan.h",
    "SDL_video.h",
    "SDL_version.h",
    "SDL_types.h",
    "SDL_touch.h",
    "SDL_timer.h",
    "SDL_thread.h",
    "SDL_syswm.h",
    "SDL_system.h",
    "SDL_surface.h",
    "SDL_stdinc.h",
    "SDL_shape.h",
    "SDL_sensor.h",
    "SDL_scancode.h",
    "SDL_rwops.h",
    "SDL_revision.h",
    "SDL_render.h",
    "SDL_rect.h",
    "SDL_quit.h",
    "SDL_power.h",
    "SDL_platform.h",
    "SDL_pixels.h",
    "SDL_opengles2.h",
    "SDL_opengles2_khrplatform.h",
    "SDL_opengles2_gl2platform.h",
    "SDL_opengles2_gl2ext.h",
    "SDL_opengles2_gl2.h",
    "SDL_opengles.h",
    "SDL_opengl.h",
    "SDL_opengl_glext.h",
    "SDL_name.h",
    "SDL_mutex.h",
    "SDL_mouse.h",
    "SDL_misc.h",
    "SDL_metal.h",
    "SDL_messagebox.h",
    "SDL_main.h",
    "SDL_log.h",
    "SDL_locale.h",
    "SDL_loadso.h",
    "SDL_keycode.h",
    "SDL_keyboard.h",
    "SDL_joystick.h",
    "SDL_hints.h",
    "SDL_hidapi.h",
    "SDL_haptic.h",
    "SDL_gesture.h",
    "SDL_gamecontroller.h",
    "SDL_filesystem.h",
    "SDL_events.h",
    "SDL_error.h",
    "SDL_endian.h",
    "SDL_cpuinfo.h",
    "SDL_copying.h",
    "SDL_config.h",
    "SDL_config_macosx.h",
    "SDL_clipboard.h",
    "SDL_blendmode.h",
    "SDL_bits.h",
    "SDL_audio.h",
    "SDL_atomic.h",
    "SDL_assert.h",
    "close_code.h",
    "begin_code.h",
]

len_of_all_files = len(hpp_files) + len(asset_files) + len(cpp_files) + len(SDL2_Files)
found_files = 0
URL = 'https://github.com/netiocom/Untitled_SDL2_Game/archive/refs/heads/master.zip'
mac_chrome_path = 'open -a /Applications/Google\ Chrome.app %s'
win_chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
with alive_bar(len_of_all_files, dual_line=True, title='Checking for ALL Files') as bar:

    for file in cpp_files:
        bar()
        if os.path.exists(f'./src/{file}'):
            found_files += 1
            print(f"{file} {colorama.Fore.CYAN}EXISTS {colorama.Style.RESET_ALL}")
        else:
            print(f"{file} {colorama.Fore.RED}NOT found{colorama.Style.RESET_ALL}")
        time.sleep(uniform(0, 0.2))

    for file in hpp_files:
        bar()
        if os.path.exists(f'./include/{file}'):
            found_files += 1
            print(f"{file} {colorama.Fore.CYAN}EXISTS {colorama.Style.RESET_ALL}")
        else:
            print(f"{file} {colorama.Fore.RED}NOT found{colorama.Style.RESET_ALL}")
        time.sleep(uniform(0, 0.2))

    for file in asset_files:
        bar()
        if os.path.exists(f'./assets/{file}') or os.path.exists(f'./assets/Player/{file}'):
            found_files += 1
            print(f"{file} {colorama.Fore.CYAN}EXISTS {colorama.Style.RESET_ALL}")
        
        else:
            print(f"{file} {colorama.Fore.RED}NOT found{colorama.Style.RESET_ALL}")
        time.sleep(uniform(0, 0.2))   
    
    for file in SDL2_Files:
        bar()
        if os.path.exists(f'./Frameworks/SDL2.framework/Headers/{file}'):
            found_files += 1
            print(f"{file} {colorama.Fore.CYAN}EXISTS {colorama.Style.RESET_ALL}")
        else:
            print(f"{file} {colorama.Fore.RED}NOT found{colorama.Style.RESET_ALL}")
        time.sleep(uniform(0, 0.2))

if found_files != len_of_all_files:
    print(f"\n{colorama.Fore.RED}{found_files}/{len_of_all_files}{colorama.Style.RESET_ALL} files found!")
    if (input("Would you like to download all the files now? (y,n) ").lower() == "y"):
        print("Redirecting to https://github.com")
        time.sleep(0.4)
        print("Open the folder (when downloaded) and run this script again.")
        time.sleep(1)
        try:
            webbrowser.get(mac_chrome_path).open(URL)
        except:
            webbrowser.get(win_chrome_path).open(URL)
    else:
        print("Not installing any files")
else:
    print(f"\n{colorama.Fore.CYAN}{found_files}/{len_of_all_files}{colorama.Style.RESET_ALL} files found!")
    print("Woohoo! You downloaded everything, you may now play the game!")