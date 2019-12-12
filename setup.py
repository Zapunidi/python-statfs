# setup.py based on https://github.com/getsentry/milksnake
from setuptools import setup


VERSION = "0.0.2"


def build_native(spec):
    build = spec.add_external_build(
        cmd=["gcc", "-fPIC", "-g", "-shared", "statfs.c", "-o", "libstatfs.so"],
        path="./src",
    )

    spec.add_cffi_module(
        module_path="statfs._native",
        dylib=lambda: build.find_dylib("statfs"),
        header_filename=lambda: build.find_header("python-statfs.h"),
    )


setup(
    name="statfs",
    version=VERSION,
    packages=["statfs"],
    author="Mathias Rav",
    license="BSD",
    author_email="mathias@scalgo.com",
    description="Python bindings to statfs in Linux.",
    include_package_data=True,
    zip_safe=False,
    platforms="any",
    install_requires=["milksnake"],
    setup_requires=["milksnake"],
    milksnake_tasks=[build_native],
)
