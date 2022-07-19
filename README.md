# ft_miniRT

group project with the amazing ![@Radel-24](https://github.com/Radel-24) :sunglasses:

## Description

We implemented a ray tracer in C using a simple graphics library(RGBA value for each pixel is set individually).<br>
Using a scene file, the user can place spheres, planes and cylinders of different sizes and colors.<br>

![the_hall scene](/images/the_hall.png)

Additionally multiple light sources with different color can be specified.

![multi_color scene](/images/multicolor.png)

For the bonus, we implemented the full ![Phong illumination Model](https://en.wikipedia.org/wiki/Phong_reflection_model) and mirror surfaces for each object.

![balls scene](/images/balls.png)

For detailed Information, check out the ![subject file](/en.subject.pdf)

## Usage

download the git repository and move into the directory
```
git clone git@github.com:tobbel42/ft_miniRT.git
cd tf_miniRT
```

compile the program using Makefile

```
make
```

to run the program with a scene file as argument

```
./miniRT test_files/wet_world.rt
```

![wet_world](/images/wet_world.png)

In the test_files folder are some additional examples to be explored :wink:

## Final Score
**123/100**

