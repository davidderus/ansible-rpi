# ansible-rpi

## Purpose

Make Raspberry Pi up and running in a few command

## Roles

- [] `common`: Setup the Rpi with with updates and better security
- [] `download_server`: Turn the Rpi in a download server for ddl and torrents
- [] `media_center`: Turn your Raspberry into a decent customizable media center
- [] `swarm_node`: Run Docker containers in a Rpis Swarm

## Dev with Vagrant

Change `hosts` to `127.1.1.0:2222` _(see `vagrant up` output for exact port)_ and run:

```
ansible-playbook playbook.yml -u vagrant --private-key .vagrant/machines/default/virtualbox/private_key
```
