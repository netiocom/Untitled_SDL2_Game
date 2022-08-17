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
    "Tilemap.cpp"
]
hpp_files = [
    "RenderWindow.hpp",
    "Utils.hpp",
    "Vector2.hpp",
    "Player.hpp",
    "Entity.hpp",
    "Tile.hpp",
    "Tilemap.hpp"
]
asset_files = [
    "microsoft.png"
]

len_of_all_files = len(hpp_files) + len(asset_files) + len(cpp_files)
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
        time.sleep(uniform(0, 1))

    for file in hpp_files:
        bar()
        if os.path.exists(f'./include/{file}'):
            found_files += 1
            print(f"{file} {colorama.Fore.CYAN}EXISTS: {colorama.Style.RESET_ALL}")
        else:
            print(f"{file} {colorama.Fore.RED}NOT found{colorama.Style.RESET_ALL}")

    for file in asset_files:
        bar()
        if os.path.exists(f'./assets/{file}') or os.path.exists(f'./assets/Player/{file}'):
            found_files += 1
            print(f"{file} {colorama.Fore.CYAN}EXISTS {colorama.Style.RESET_ALL}")
        
        else:
            print(f"{file} {colorama.Fore.RED}NOT found{colorama.Style.RESET_ALL}")
            time.sleep(uniform(0, 1))

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