FROM quay.io/pypa/manylinux2010_x86_64
WORKDIR /py
RUN yum -y install gcc libffi-devel
COPY src/ src/
COPY statfs/ statfs/
COPY setup.py .
RUN \
	/opt/python/cp27-cp27mu/bin/python setup.py bdist_wheel --verbose && \
	for wheel in dist/*-linux_*.whl; do auditwheel repair $wheel -w dist/ && rm $wheel; done
