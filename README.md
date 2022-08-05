
# boost python 编译
1. download boost


https://onboardcloud.dl.sourceforge.net/project/boost/boost/1.66.0/boost_1_66_0.tar.bz2

2. compile envs


python2.7.10 gcc 4.8.5

3. compile command


./bootstrap.sh --prefix=/data/home/rexyuan/ocrenv/boost166/ --with-python=/data/home/rexyuan/miniconda3/envs/py27/bin/py2
./b2 install


