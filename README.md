# ansible-rpi 0.3.1

## Purpose

Make Raspberry Pi up and running in a few command.

Tested on a Rpi 3 B+ and a Rpi 1 B.

## Roles

### Done

- `common`: Setup the Rpi with with updates and better security
  - Locale setup
  - System upgrade (*including kernel*)
  - Adding some useful packages (*curl, vim, tmux, git…*)
  - UFW firewall rules allowing user-specified ports and protocols
  - Logwatch for system status emails (*via SSMTP*)
  - SSH with key-only authentification
  - Custom sudo user for rpi (*thus disabling pi as Rpi sudoer*)
  - `oh-my-zsh` install and vim as default editor
  - Dynamic network folder and local drive setup (*Works with SAMBA and include basic credentials management*)
  - Optionnal hostname update and Zeroconf
  - Optionnal custom SSH banner
  - Optionnal Wifi config
  - Optionnal Mosh support
- `download_server`: Turn the Rpi in a download server for ddl and torrents
  - Aria2 daemon
  - RPC interface for remote monitoring with optionnal SSL encryption
  - Shared downloads directory (*may be replaced by a previously configured network folder*)
- `media_center`: Turn your Raspberry into a decent customizable media center
  - Kodi basic installation with separate user
  - Dynamic sources creation (*may be linked to previously configured network folders*)
  - Buffer handling optimized for a Raspberry
  - Optionnal `kodi` user with `kodi-standalone` and a minimal Openbox setup

### Incoming

- `swarm_node`: Setup a Rpi as a Docker Machine and join a Docker Swarm

## Setup

### With examples

```
# First
cp hosts.inc hosts

# Then
cp playbook.yml.inc playbook.yml
cp variables.yml.inc host_vars/my-host.yml
```

### Usage

First update the `hosts` file to target your Rpis.

I recommend using an up-to-date [Raspbian Lite image](https://downloads.raspberrypi.org/raspbian_lite_latest).

Make sure that the Rpi is SSHable (**latest raspbian lite images come with SSH
disabled by default, creating a file with name "ssh" in boot partition is
required to enable it.**).

Then the first time run:

```
ansible-playbook playbook.yml -u pi --ask-pass
```

### Dev with Vagrant

First run:

```
ansible-playbook playbook.yml -i hosts.dev
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

## User password generation

`password_hash` is a useful Jinja filter but uses 656000 rounds for SHA512 hashing.

The default is 5000 in glibc [1], and it adds an important computing cost on a Rpi.

This may cause axtra slowness on user authentification (*ie. sudo password prompt*)

Please use the following command to generate a user password hash [2]:

```bash
python -c "from passlib.hash import sha512_crypt; import getpass; print sha512_crypt.encrypt(getpass.getpass(), rounds=5000)"
```

[1](https://github.com/ansible/ansible/issues/15326)
[2](https://docs.ansible.com/ansible/faq.html#how-do-i-generate-crypted-passwords-for-the-user-module)
