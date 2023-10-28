FROM python:3.10-slim-bullseye
ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1
WORKDIR /app
COPY requirements.txt requirements.txt
RUN pip3 install -r requirements.txt
COPY . .
# dev only
CMD [ "python3", "-m" , "flask", "run", "--host=0.0.0.0"]
# for prod
# CMD ["gunicorn", "-w", "4", "wsgi:app", "--bind", "0.0.0.0:8000"]