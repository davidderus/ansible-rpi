---

###############
# Common Role #
###############

# New Rpi identity
rpi_user_name: neo
rpi_user_password: $CHANGE_ME$Ovaexae2queimeerahraashahchah5aiyeexae1ahi3aiwiek3ohFaib3gahpooWoodah8que8chiephureghang7Eiz4baig0BooshahCacha3oyeiYeu6Wo1sheiph

# Updating locales
rpi_locale:
  - "fr_FR.UTF-8 UTF-8"

# rpi_zsh_theme: robbyrussell

# Logwatch

logwatch_email: youremail@example.com

# SSH

ssh_port: 4480
ssh_public_keys:
  - ~/.ssh/id_rsa.pub

# See roles/common/templates/ssh/banner.j2
ssh_custom_banner: True

# Firewall

allowed_ports:
  - 4480 # SSH custom port
  - 6800 # Aria2 Daemon port

# Wifi handling (disabled by default)

with_wifi: False
wifi_ssid: my_ssid
wifi_password: my_password
wifi_proto: RSN
wifi_key: WPA-PSK
wifi_pairwise: CCMP

with_vim: True

# with_mosh: True

# with_automount: True

# Type is required. Mounted devices are available at /mnt/ for shared_group
# automount_local_devices:
#   - { name: 'mydevice', label: 'MY_DEVICE', type: 'ext4' }

# Default type to cifs. Available at /media/ for shared_group
# automount_network_folders:
#   - { name: 'mydrive', network_folder: '//192.168.0.10/mydrive', domain: 'WORKGROUP', user: 'my_name', password: 'my_password' }

########################
# Download server Role #
########################

# Creates a dedicated user

# By default rpi_user_password is the prc token
# aria2_rpc_token:

# aria2_rpc_port: 6800

# ds_downloads_root (by default: /home/{{ ds_user_name }}). Will create a `downloads` directory to put downloaded files in.
# ds_downloads_root: /media/mydrive

#####################
# Media Center Role #
#####################

# Does not create a dedicated user (user rpi one)

# kodi_source_files: []
# kodi_source_music: []
# kodi_source_pictures: []
# kodi_source_programs: []
# kodi_source_videos: []
