all:
	echo 'hello'

	git submodule deinit -f .

	git submodule update --init --recursive

	cp --recursive kyria qmk_firmware/keyboards/splitkb/kyria/keymaps/juno

	#qmk flash

