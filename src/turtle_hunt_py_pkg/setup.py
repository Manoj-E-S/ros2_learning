from setuptools import find_packages, setup

package_name = 'turtle_hunt_py_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='manoj',
    maintainer_email='manoj.es.professional@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'turtle_spawner = turtle_hunt_py_pkg.turtle_spawner:main',
            'turtle1_controller = turtle_hunt_py_pkg.turtle1_controller:main'
        ],
    },
)
