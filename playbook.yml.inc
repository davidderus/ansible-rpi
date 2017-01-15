---

- name: Configure and securise any Rpi

  hosts: servers
  roles:
    - common

  become: yes

- name: Setup and manage a download server

  hosts: download-servers
  roles:
    - download_server

  become: yes

- name: Setup a media center

  hosts: media-centers
  roles:
    - media_center

  become: yes
