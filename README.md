# ft_miniRT

group project with the amazing @radel24 :sunglasses:

## Task

We implemented a ray tracer in C using a simple graphics library(RGBA value for each pixel is set).
Using a scene file, the user can place spheres, planes and cylinders of different sizes and colors.

![the_hall scene](/images/the_hall.png)

Additionally multiple light sources with different color can be specified.

![multi_color scene](/images/multicolor.png)

For the bonus, we implemented the full ![Phong illumination Model](https://en.wikipedia.org/wiki/Phong_reflection_model) and
mirror surfaces for each object

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

In the test_files folder are some examples to be explored :wink:

![wet_world](/images/wet_world.png)

## Final Score
**123/100**

