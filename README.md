# ansible-rpi 0.0.3

## Purpose

Make Raspberry Pi up and running in a few command

## Roles

### Done

- `common`: Setup the Rpi with with updates and better security
  - UFW for firewall rules
  - Logwatch for system status emails
  - SSH with key-only authentification
  - Optionnal Wifi config
- `download_server`: Turn the Rpi in a download server for ddl and torrents
  - Aria2 daemon
  - RPC interface for remote monitoring
- `media_center`: Turn your Raspberry into a decent customizable media center
  - Kodi basic installation
  - Dynamic sources creation

### Incoming

- `swarm_node`: Run Docker containers in a Rpis Swarm

### TODO

- Mosh support for remote login (*+ ufw rules*)
- Vim editor by default
- Conditionnal Kodi backport only for Debian

## Dev with Vagrant

Run:

```
ansible-playbook playbook.yml -u vagrant --private-key .vagrant/machines/default/virtualbox/private_key
```

## Usage

First update the `hosts` file to target your Rpis.

Then the first time run:

```
ansible-playbook playbook.yml -u pi
```
