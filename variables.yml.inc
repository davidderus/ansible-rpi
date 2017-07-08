---

###############
# Common Role #
###############

# New Rpi identity
server_user_name: neo

# Must be a SHA-512 hash with like 5000 rounds (not as much as Ansible password_hash – 656000 — otherwise authentification may take a while)
server_user_password_hash: $6$KU0KJ6OtZYzWlhbj$HWRhIMQL37UfEBkR1nwKre08LbM9LvAZr/lZ7iHz9VW7AfSu88RaADbtoxfJEwiW3DaWIzKUnu8mweeTg9Qxw.

# To set custom user groups, use to following variable:
# server_user_groups: "…"

# Updating locales if required (default to en_US.UTF-8)
server_locales:
  - fr_FR.UTF-8

# Enable custom hostname for Rpi and install zeroconf and libnss-mdns
# with_custom_hostname: True
# server_host_name: "rpi-{{ server_user_name }}"

# You can define a group shared between roles (here it will be rpi-neo-shared)
# This is required for mixing server role with download_server and media_center
# server_shared_group: mygroup

# By default we allow server upgrade and reboot. You can disable this behaviour
# with:
# server_allow_upgrade: False
# server_allow_reboot: False

# Enable zsh with the line below:
# with_zsh: True
# server_zsh_theme: robbyrussell

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
  - { port: 22, proto: 'tcp' }
  - { port: 6800, proto: 'tcp' } # Aria2 Daemon port
# - { port: 8070, proto: 'tcp' } # Kodi HTTPServer Connection
# - { port: 9777, proto: 'udp' } # Kodi EventServer Connection
# - { port: 9981, proto: 'tcp' } # Tvheadend admin

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
# By default the `automount_group` is `root` or `server_shared_group` if defined

# Type and UUID are required. Mounted devices are available at /mnt/ for automount_group
# To get those informations, run `sudo lsblk -f` against the host.
# automount_local_devices:
#   - { name: 'mydevice', uuid: 'MY-DEVICE-UUID', type: 'ext4' }

# Default type to cifs. Available at /media/ for automount_group
# automount_network_folders:
#   - { name: 'mydrive', network_folder: '//192.168.0.10/mydrive', domain: 'WORKGROUP', user: 'my_name', password: 'my_password' }

# It may also be a good idea to unprivileged the pi user after creating the new server owner
# server_unsudoed_users:
#   - pi

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

# Enable tvheadend installation with the following line (disabled by default)
# kodi_with_tvheadend: true
# You can also change these default values:
# kodi_tvheadend_username: admin
# kodi_tvheadend_password: admin

###################
# Rpi Docker Role #
###################

# Change the storage driver
# rd_storage_driver: overlay

# Update limits
# rd_limit_nofile: 1048576
# rd_limit_nproc: 1048576
# rd_limit_core: infinity

# Deactivate iptables addition by Docker (_thus enabling custom NAT and UFW forward policy_)
# rd_iptables: false

# Custom bridge (_if needed_)
# rd_docker_bridge: docker0
# rd_docker_bridge_ip_range: 172.17.0.0/16

#####################
# Audio Center Role #
#####################

# This role requires a PREMIUM Spotify account
# The following variables are REQUIRED:
#
# ac_respot_url: https://url-to-a-valid-and-compatible-librespot-binary
# ac_respot_checksum: 000000
# ac_spotify_user: my-username
# ac_spotify_password: my-password

# These variables are optionnal:
# ac_respot_output_dir: /usr/local/lib # directory where the binary is stored
# ac_spotify_device_name: "{{ inventory_hostname }}" # device name used by Spotify
# ac_respot_bitrate: 320 # Bitrate (320 is the maximum value)
# ac_respot_device: hw:CARD=ALSA,DEV=0 # Audio device to play music with
# ac_respot_backend: alsa # Audio backend
# ac_respot_user_dir: '/etc/librespot' # librespot directory used to store cache
