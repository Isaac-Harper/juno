OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays

ENCODER_ENABLE = yes       # Enables the use of one or more encoders

RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
RGBLIGHT_ANIMATIONS = no  # Enables rgb animations
RGB_MATRIX_ENABLE = no

MOUSEKEY_ENABLE = yes
KEY_LOCK_ENABLE = yes


WPM_ENABLE = yes	# Enable word per minute counter

PROGRAMMABLE_BUTTON_ENABLE = no
CAPS_WORD_ENABLE = no

MIDI_ENABLE = no
AUDIO_ENABLE = no
BLUETOOTH_ENABLE = no

TAP_DANCE_ENABLE=yes


SPACE_CADET_ENABLE = yes
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no

CONSOLE_ENABLE = no

LTO_ENABLE = yes	# Makes hex file smaller
EXTRAFLAGS += -flto

