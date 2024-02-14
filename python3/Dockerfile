FROM nvcr.io/nvidia/cuda:11.8.0-devel-ubuntu20.04

# 设置环境变量
ENV JUPYTER_PORT=8888 \
    NOTE_BOOK_DIR=/app/notebooks \
    MINICONDA_VERSION=latest \
    CONDA_DIR=/opt/miniconda3

# 暴露 Jupyter 端口
EXPOSE ${JUPYTER_PORT}

# 添加腾讯软件源并安装所需包
RUN echo "deb http://mirrors.tencent.com/ubuntu/ focal main restricted universe multiverse \n \
    deb http://mirrors.tencent.com/ubuntu/ focal-security main restricted universe multiverse \n \
    deb http://mirrors.tencent.com/ubuntu/ focal-updates main restricted universe multiverse \n \
    deb-src http://mirrors.tencent.com/ubuntu/ focal main restricted universe multiverse \n \
    deb-src http://mirrors.tencent.com/ubuntu/ focal-security main restricted universe multiverse \n \
    deb-src http://mirrors.tencent.com/ubuntu/ focal-updates main restricted universe multiverse \n" > /etc/apt/sources.list && \
    apt update && \
    apt install -y nfs-common iproute2 ceph-fuse iputils-ping vim git cron curl wget && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 安装 Miniconda
RUN wget https://repo.anaconda.com/miniconda/Miniconda3-${MINICONDA_VERSION}-Linux-x86_64.sh -O /tmp/miniconda.sh && \
    chmod +x /tmp/miniconda.sh && \
    /tmp/miniconda.sh -b -p ${CONDA_DIR} && \
    rm /tmp/miniconda.sh && \
    ${CONDA_DIR}/bin/conda install -y python=3.10 jupyter -c conda-forge --quiet && \
    ${CONDA_DIR}/bin/conda install -y pytorch torchvision torchaudio pytorch-cuda=11.8 -c pytorch -c nvidia && \
    ${CONDA_DIR}/bin/conda clean -afy

# 设置环境变量以包括 conda 在 PATH 中
ENV PATH=${CONDA_DIR}/bin:${PATH}

# 设置工作目录
WORKDIR ${NOTE_BOOK_DIR}

# 设置 ENTRYPOINT 以使用 conda 初始化的 shell
# ENTRYPOINT ["/bin/bash", "--login", "-c"]

# 设置默认启动命令
CMD jupyter notebook --notebook-dir=${NOTE_BOOK_DIR} --ip=0.0.0.0 --port=${JUPYTER_PORT} --no-browser --allow-root --NotebookApp.token='' --NotebookApp.password=''
