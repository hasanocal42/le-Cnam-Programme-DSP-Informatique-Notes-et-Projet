# KEYCLOAK

Ce projet est pour déployer Keycloak (16.0) via docker-compose

## PRE-REQUIS

- [Docker]()
- [docker-compose]()

## UTILISATION

- Editer les variables dans le .env
```bash
nano .env
```

> Modifier les mots de passe pour la base de données et keycloak ainsi que le domaine, l'adresse email, l'administrateur

```bash
docker-compose up -d
# ./install-and-deploy.sh
```

## TODO 

- [ ] Générer les mdp avec openssl et afficher mdp admin via script bash
- [ ] Script install-and-deploy.sh:
    - Generate random mdp
    - put in .env
    - docker-compose up -d
    - affiche user et mdp admin