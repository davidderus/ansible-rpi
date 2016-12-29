---

- name: Configure and securise any Rpi

  hosts: all
  roles:
    - common

  become: yes

- name: Setup and manage a download server

  hosts: download_servers
  roles:
    - download_server

  become: yes

- name: Setup a media center

  hosts: media_centers
  roles:
    - media_center

  become: yes
