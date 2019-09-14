"""Script to hotswap plugin from bakkesmod process.

1. Connects to BakkesMod rcon
2. Unloads plugin
4. Loads plugin


"""
import sys, os, shutil, websockets, time
import asyncio

bakkesmod_plugin_folder = "C:/Program Files (x86)/Steam/steamapps/common/rocketleague/Binaries/Win32/bakkesmod/plugins/"
bakkesmod_server = 'ws://127.0.0.1:9002'
rcon_password = 'password'

async def main_loop():
	async with websockets.connect(bakkesmod_server, timeout=.1) as websocket:
		await websocket.send('rcon_password ' + rcon_password)
		auth_status = await websocket.recv()
		assert auth_status == 'authyes'
		await websocket.send("plugin unload " + plugin_name)
		time.sleep(0.1)
		await websocket.send("plugin load " + plugin_name)


if __name__ == '__main__':
	if len(sys.argv) == 1:
		exit()

	plugin_name = sys.argv[1]
	plugin_name = plugin_name[0:plugin_name.index('.')]
	asyncio.get_event_loop().run_until_complete(main_loop())
