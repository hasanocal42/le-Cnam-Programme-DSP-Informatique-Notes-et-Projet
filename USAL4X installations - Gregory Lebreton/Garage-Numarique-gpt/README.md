# GARAGE GPT :alien:

![CHATGPT](https://media2.giphy.com/media/qAtZM2gvjWhPjmclZE/giphy.gif?cid=ecf05e47pji6o2vjk5sa2thp1f8yqjtywlt7vm9m45nqykzx&ep=v1_gifs_search&rid=giphy.gif&ct=g)

Projet pour héberger un Chat-GPT local s'appuyant sur le projet [LocalAI](https://localai.io/)
utilisant une simple flaskapp comme frontend.

:warning: seulement le model ggml-gpt4all-j (gpt-3.5-turbo) est pris en charge pour le moment

## PREREQUIS :paperclip:

- Docker :whale:

## MODELS :moyai:

- compatibles: [LocalAI](https://github.com/go-skynet/model-gallery)
- tous: [HugginFace](https://huggingface.co/models?search=ggml)  

## CONFIGURATION :wrench:

La configuration se fait dans le .env.local:
- THREADS -> nombre de cores du CPU utilisés (privilègier le nombre de cores physiques au max)  
<img src="https://indipest.files.wordpress.com/2021/03/bw6d5zz.gif" width="200px">
- DEFAULT_MODEL -> Le modèle chargé par défault (dans la RAM)
- PRELOAD_MODELS -> Renseigner les adresses des modèles que l'on veux télécharger via l'adresse https://github.com/go-skynet/model-gallery/model.yaml

:warning: L'image LocalAI fait un peu plus de 12Go et les modèles 7B ou 13B font en moyenne 4 à 6Go

### logos

Pour modifier les logos:
- flask-app/static/logo.png (footer)
- flask-app/static/favicon.ico
- flask-app/static/loader.gif (loading gif)

Pour modifier les titres:
- flask-app/templates/base.html ligne 13 et 25

## UTILISATION :checkered_flag:

- Premier lancement:
```bash
docker compose up -d
```

:hourglass: Attendre que la stack se build :coffee:

- L'interface est accessible à cette adresse:  

> http://localhost:5000

- Après les premier lancement:

```bash
nano .env
REBUILD=false
```

> A chaque modification des PRELOAD_MODELS, REBUILD=true

#### voir les logs

```bash
docker compose logs -f
```

## MODELS OK

:white_check_mark: ggml-gpt4all-j.bin (= gpt-turbo-3.5)  
:white_check_mark: stablediffusion (image generator)  
- [ ] wizardlm-13b-v1.1-superhot-8k.ggmlv3.q4_0.bin
- [ ] open-llama-7b-q4_0.bin -> HS pour le moment
- [ ] whisper (audio to text)
- [ ] bloomz (traduction)
- [ ] wizardcode (code) -> URL model HS

## TEST HARDWARE :computer:

| MODEL            | PROMPT            | i5-8350U 16G RAM      | RYZEN 7 5800X 32G RAM | TEMP
| :--------------- |:-----------------:| ---------------------:|:----------------:|:------:|
| GPT-TURBO-3.5    | WRITE JS FUNCTION | 41S                   | 16s              | 0.5    |
| STABLEDIFFUSION  | BLUE FLOWER       | 90s                   | 20S              | X      |


## TO DO :bookmark_tabs:

:white_check_mark: une page gpt / une page stablediffusion avec navbar dans base.html  
:white_check_mark: Temperature bouton  
:white_check_mark: formater code (```js ```)  
:white_check_mark: Flask app frontend  
:white_check_mark: authentification Keycloak -> https://git.legaragenumerique.fr/GARAGENUM/flask-keycloak  
- [ ] bouton stop generating
- [ ] Traduction via [LibreTranslate](https://github.com/LibreTranslate/LibreTranslate) :gb: -> :fr:
- [ ] conserver context (sqlite / json / session ?)
- [ ] restart container si timeout  
- [ ] utiliser GPU 
- [ ] entraîner avec big GPU

### bugs :ghost:

- [ ] permissions dossier models (root != user)
