
# boost python 编译
1. download boost
	https://onboardcloud.dl.sourceforge.net/project/boost/boost/1.66.0/boost_1_66_0.tar.bz2
2. compile envs
	python2.7.10 gcc 4.8.5
3. compile options & config
	./bootstrap.sh --prefix=/data/home/rexyuan/ocrenv/boost166/ --with-python=/data/home/rexyuan/miniconda3/envs/py27/bin/py2
4. compile command
	./b2 install

# compile project
1. mkdir build
2. cd build
3. cmake  -DCMAKE_BUILD_TYPE=DEBUG ..
4. make

# test
python classes.py

