# ansible-rpi

## Purpose

Make Raspberry Pi up and running in a few command

## Roles

- [X] `common`: Setup the Rpi with with updates and better security
- [] `download_server`: Turn the Rpi in a download server for ddl and torrents
- [] `media_center`: Turn your Raspberry into a decent customizable media center
- [] `swarm_node`: Run Docker containers in a Rpis Swarm

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
