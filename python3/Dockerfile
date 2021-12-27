FROM continuumio/miniconda3
EXPOSE 8888
ENV JUPYTER_PORT=8888
ENV NOTE_BOOK_DIR=./notebooks

RUN conda install -c conda-forge mamba && \
    mamba install jupyter -y --quiet && \
    pip install pillow -y

CMD jupyter notebook \
    --notebook-dir=${NOTE_BOOK_DIR} --ip='*' --port=${JUPYTER_PORT} \
    --no-browser --allow-root

WORKDIR /app
