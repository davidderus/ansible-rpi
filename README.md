# ansible-rpi 0.0.4

## Purpose

Make Raspberry Pi up and running in a few command

## Roles

### Done

- `common`: Setup the Rpi with with updates and better security
  - Locale setup
  - Hostname update
  - Adding some useful packages (*curl, vim, tmux, git, avahi-daemon…*)
  - UFW firewall rules allowing user-specified ports
  - Logwatch for system status emails (*via Postfix*)
  - SSH with key-only authentification
  - Zeroconf with Avahi Daemon
  - `oh-my-zsh` install and vim as default editor
  - Dynamic network folder and local drive setup (*Works with SAMBA and include basic credentials management*)
  - Optionnal custom SSH banner
  - Optionnal Wifi config
  - Optionnal Mosh support
- `download_server`: Turn the Rpi in a download server for ddl and torrents
  - Aria2 daemon
  - RPC interface for remote monitoring
  - Shared downloads directory (*may be replaced by a previously configured network folder*)
- `media_center`: Turn your Raspberry into a decent customizable media center
  - Kodi basic installation
  - Dynamic sources creation (*may be linked to previously configured network folders*)

### Incoming

- `swarm_node`: Run Docker containers in a Rpis Swarm

### TODO

- Safe credential storage
- Use as an ansible module

## Dev with Vagrant

First run:

```
ansible-playbook playbook.yml -u vagrant --private-key .vagrant/machines/default/virtualbox/private_key
```

Next runs:

```
# Editing the hosts file may be required to update the SSH port
# A vagrant reload may also be needed
# Checks access with
ansible all -m ping -u neo

# Execute updated playbook
ansible-playbook playbook.yml -u neo --ask-become-pass
```

## Usage

First update the `hosts` file to target your Rpis.

Then the first time run:

```
ansible-playbook playbook.yml -u pi --ask-become-pass
```
