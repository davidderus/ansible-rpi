---

###############
# Common Role #
###############

# New Rpi identity
rpi_user_name: neo

# Must be a SHA-512 hash with like 5000 rounds (not as much as Ansible password_hash – 656000 — otherwise authentification may take a while)
rpi_user_password_hash: $6$KU0KJ6OtZYzWlhbj$HWRhIMQL37UfEBkR1nwKre08LbM9LvAZr/lZ7iHz9VW7AfSu88RaADbtoxfJEwiW3DaWIzKUnu8mweeTg9Qxw.

# Updating locales
rpi_locale:
  - "fr_FR.UTF-8 UTF-8"

# Enable custom hostname for Rpi and install zeroconf and libnss-mdns
# with_custom_hostname: True
# rpi_host_name: "rpi-{{ rpi_user_name }}"

# rpi_zsh_theme: robbyrussell

# SSMTP

ssmtp_email: admin@gmail.com

# https://security.google.com/settings/security/apppasswords
ssmtp_auth_pass: MyUniqMailKey

# Other vars:
# ssmtp_mailhub: smtp.gmail.com:587
# ssmtp_auth_user: admin@gmail.com

# Logwatch

logwatch_email: youremail@example.com

# SSH

# Changing this implies updating `allowed_ports` by adding the new port
# AND leaving port 22 for the first setup (otherwise ansible may stop)
ssh_port: 22
ssh_public_keys:
  - ~/.ssh/id_rsa.pub

# See roles/common/templates/ssh/banner.j2
ssh_custom_banner: True

# Firewall

allowed_ports:
  - 22
  - 6800 # Aria2 Daemon port
# - 8070 # Kodi HTTPServer Connection
# - 9777 # Kodi EventServer Connection

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

# Must be set in order to access aria2
# aria2_rpc_token:

# aria2_rpc_port: 6800

# To enable traffic encryption (disabled by default)
# aria2_rpc_encrypted: True
# aria2_cert_subject: "/C=GB/ST=London/L=London/O=Global Security/OU=IT Department/CN=example.com"

# ds_downloads_root (by default: /home/{{ ds_user_name }}). Will create a `downloads` directory to put downloaded files in.
# ds_downloads_root: /media/mydrive

#####################
# Media Center Role #
#####################

# Does not create a dedicated user (eg. user neo)

# kodi_source_files: []
# kodi_source_music: []
# kodi_source_pictures: []
# kodi_source_programs: []
# kodi_source_videos: []

# Enable buffering for slow networks
# with_kodi_buffering: True

# Using 418M of RAM maximum (may crash if not available):
# kodi_read_buffer_factor: 20
# kodi_buffer_size: 139460608

# Kodi session name and password are updatable (_default password is `kodi`_)
# kodi_username: kodi
# kodi_password_hash: $6$iLBM8EeXOMRMb0I3$gRrJmyVcCeMl.JT7DKLG1XIYDl6/qq6FB99t.IO2Hy87ykxKLSZ0GUVqK/.N7N5gfQMJHiBAAApCM.geeia1z.
