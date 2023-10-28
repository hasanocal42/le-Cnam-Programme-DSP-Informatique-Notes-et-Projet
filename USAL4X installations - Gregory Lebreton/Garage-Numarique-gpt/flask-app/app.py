import os, re
import requests, time
# from llama_cpp import Llama
# import dotenv
from dotenv import load_dotenv
from flask import Flask, redirect, render_template, request, url_for

app = Flask(__name__)
model = "ggml-gpt4all-j.bin"

load_dotenv()
host = os.getenv("LOCALAI_HOST")

# CHAT BOT: GPT-TURBO-3.5
@app.route("/", methods=("GET", "POST"))
def index():

    result = ''
    temps = ''

    if request.method == "POST":

        question = request.form["question"]
        temp = request.form["temperature"]

        url = "http://" + host + ":8080/v1/chat/completions" 

        payload = {
        #  "role": "system", "content": "You are Yoda, the character of Star Wars and you answer the question like he would.",
            "model": 'gpt-3.5-turbo',
            "messages": [{"role": "user", "content": question}],
            "temperature": float(temp)
        }

        tic = time.perf_counter()

        try:
            response = requests.post(url, json=payload)
            if response.status_code == 200:
                result = '<md>' + response.json()['choices'][0]['message']['content'] + '</md>'
            else:
                result = "Erreur de connection avec l'API (l'API n'est pas disponible, regardez les logs: docker compose logs -f)"

        except:
            result = "Erreur de connection avec l'API (configuration)"

        toc = time.perf_counter()
        
        temps = f"temps de réponse: {toc - tic:0.4f} seconds"     

    return render_template("index.html", result=result, time=temps)


# IMAGE GENERATOR: STABLEDIFFUSION
@app.route("/image", methods=("GET", "POST"))
def image():

    result = ''
    temps = ''

    if request.method == "POST":

        question = request.form["image"]
        url = "http://" + host + ":8080/v1/images/generations"

        headers = {
            "Content-Type": "application/json"
        }

        data = {
            "prompt": question,
            "size": "256x256",
            "directory": "/tmp"
        }

        tic = time.perf_counter()

        try:
            response = requests.post(url, headers=headers, json=data)
            if response.status_code == 200:
                image_url = response.json()['data'][0]['url'].replace("local-ai", "localhost")
            else:
                result = "Erreur de connection avec l'API (l'API n'est pas disponible, regardez les logs: docker compose logs -f)"

        except:
            result = "Erreur de connection avec l'API (configuration)"
        
        toc = time.perf_counter()
        
        temps = f"temps de réponse: {toc - tic:0.4f} seconds"
        result = '<img src=' + image_url + ' >'       


    return render_template("image.html", result=result, time=temps)

