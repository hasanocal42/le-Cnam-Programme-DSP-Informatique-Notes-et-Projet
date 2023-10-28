# DOCKER :whale:

## INSTALLATION ON DEBIAN 12:

```bash
# dépendances
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg

# clef GPG
sudo install -m 0755 -d /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
sudo chmod a+r /etc/apt/keyrings/docker.gpg

# url dépôt
echo "deb [arch="$(dpkg --print-architecture)" signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

# install docker + plugins
sudo apt-get update && sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

# docker sans sudo
sudo usermod -aG docker $(whoami)
newgrp docker
```

## DOCUMENTATION :book:

> [DOCKER](https://docs.docker.com/engine/install/debian/)