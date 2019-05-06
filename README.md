Generating images of a sphere under orthographic projection using a reflectance model.

The surface of the object was given by the equation:

![img](http://latex.codecogs.com/svg.latex?z%28x%2Cy%29%3Dz_0%2B%5Csqrt%7Br%5E2-%28x%5E2%2By%5E2%29%7D)

The vector components of the normal vector to that sphere was given by the gradient vector such that,

\frac{dz}{dx}=\frac{-x}{\sqrt{r^2-(x^2+y^2)}\
\frac{dz}{dy}=\frac{-y}{\sqrt{r^2-(x^2+y^2)}\
\frac{dz}{dz}=1\

The normal vector was normalized to obtain the unit normal vector,

\hat{N}={\frac{-x}{r}\vec{i}+\frac{-y}{r}\vec{j}+\frac{\sqrt{r^2-(x^2+y^2)}}{r}\vec{k}\

The camera was fixed at the location given by the vector 
![img](http://latex.codecogs.com/svg.latex?%5Chat%7BV%7D%3D%5C%7B0%2C0%2C1%5C%7D)
. The light source was varied at the location given by the vector 
![img](http://latex.codecogs.com/svg.latex?%5Chat%7BS%7D)
. The object had a Lambertian surface profile and the scene radiance was given by the equation,

L=aL_l+(1-a)L_s
L_l=cos(\theta)
L_s=\exp\{-(\frac{\alpha}{m})^2\}

![img](http://latex.codecogs.com/svg.latex?)
![img](http://latex.codecogs.com/svg.latex?)
![img](http://latex.codecogs.com/svg.latex?)
![img](http://latex.codecogs.com/svg.latex?)

where 
![img](http://latex.codecogs.com/svg.latex?L_%7Bl%7D)
was the scene radiance due to the Lambertian refection and 
![img](http://latex.codecogs.com/svg.latex?L_%7Bs%7D)
was the scene radiance due to the specular reflection. The angle 
![img](http://latex.codecogs.com/svg.latex?%5Ctheta)
was given by the angle between the vectors 
![img](http://latex.codecogs.com/svg.latex?%5Chat%7BS%7D)
and 
![img](http://latex.codecogs.com/svg.latex?%5Chat%7BN%7D)
and the angle $\alpha$ was given by the angle between the vectors 
![img](http://latex.codecogs.com/svg.latex?%5Chat%7BS%7D)
and 
![img](http://latex.codecogs.com/svg.latex?%5Chat%7BH%7D)
. The unit angular bisector vector 
![img](http://latex.codecogs.com/svg.latex?%5Chat%7BH%7D)
was given by,\
\hat{H}=\frac{\hat{V}+\hat{S}}{|\hat{V}+\hat{S}|}

The parameters r, a, and m, radius of sphere, radiance constant, and material surface roughness, respectively, were varied to observe their effects.

<p align="center">
  <img src="https://imgur.com/eUoBpE7.jpg" alt="Figure 1. S = {0, 0, 1}, r = 50, a = 0.5, m = 1" width="300"/>
</p>
<p align="center">Figure 1. S = {0, 0, 1}, r = 50, a = 0.5, m = 1<p align="center">

_Figure 1_ displays the orthogonal projection of the object when the parameters were set to "default". Here, the light source positioned at the same location as the camera.

<p align="center">
    <img src="https://imgur.com/b96S7KS.jpg" alt="Figure 2. S = {sqrt(1/3), sqrt(1/3), sqrt(1/3)}, r = 50, a = 0.5, m = 1" width="300"/>
</p>
<p align="center">Figure 2. S = {sqrt(1/3), sqrt(1/3), sqrt(1/3)}, r = 50, a = 0.5, m = 1<p align="center">

_Figure 2_ displays the image of the object when the light source was moved away from the default location to positive quadrant of $xy-$plane. The light source points to the object from a $45$ degree angle.

<p align="center">
    <img src="https://imgur.com/inVYBom.jpg" alt="Figure 3. S = {1, 0, 0}, r = 50, a = 0.5, m = 1" width="300"/>
</p>
<p align="center">Figure 3. S = {1, 0, 0}, r = 50, a = 0.5, m = 1"<p align="center">

_Figure 3_ displays the image of the object when the light source was again moved to the $x-$axis. Therefore, the light was shined from the right side of the sphere.

<p align="center">
    <img src="https://imgur.com/ex9eQak.jpg" alt="Figure 4. S = {0, 0, 1}, r = 10, a = 0.5, m = 1" width="300"/>
</p>
<p align="center">Figure 4. S = {0, 0, 1}, r = 10, a = 0.5, m = 1<p align="center">
<p align="center">
    <img src="https://imgur.com/LBmh14j.jpg" alt="Figure 5. S = {0, 0, 1}, r = 100, a = 0.5, m = 1" width="300"/>
</p>
<p align="center">Figure 5. S = {0, 0, 1}, r = 100, a = 0.5, m = 1<p align="center">

_Figure 4_ and _Figure 5_ displays the image of the object when the radius of the object was decreased and increased, respectively. Therefore, the image of the sphere became smaller and bigger, respectively.

<p align="center">
    <img src="https://imgur.com/bubhKzU.jpg" alt="Figure 6. S = {0, 0, 1}, r = 50, a = 0.1, m = 1" width="300"/>
</p>
<p align="center">Figure 6. S = {0, 0, 1}, r = 50, a = 0.1, m = 1<p align="center">
<p align="center">
    <img src="https://imgur.com/IXwvlXe.jpg" alt="Figure 7. S = {0, 0, 1}, r = 50, a = 1, m = 1" width="300"/>
</p>
<p align="center">Figure 7. S = {0, 0, 1}, r = 50, a = 1, m = 1<p align="center">

_Figure 6_ and _Figure 7_ displays the image of the object when the Lambertian scene radiance constant, a, was changed. As the constant, a, increased, the gradation of the light became more even. The surface reflected light more evenly as the constant increased and appeared more matte.

<p align="center">
    <img src="https://imgur.com/reMFGq3.jpg" alt="Figure 8. S = {0, 0, 1}, r = 50, a = 0.5, m = 0.1" width="300"/>
</p>
<p align="center">Figure 8. S = {0, 0, 1}, r = 50, a = 0.5, m = 0.1<p align="center">
<p align="center">
    <img src="https://imgur.com/6Xxv7uX.jpg" alt="Figure 9. S = {0, 0, 1}, r = 50, a = 0.5, m = 10000" width="300"/>
</p>
<p align="center">Figure 9. S = {0, 0, 1}, r = 50, a = 0.5, m = 10000<p align="center">

_Figure 8_ and _Figure 9_ displays the image of the object when the material roughness was changed. As roughness increased, the reflectance became less matte. When the roughness was small, the term 
![img](http://latex.codecogs.com/svg.latex?L_%7Bs%7D)
dominated in the scene radiance, therefore, creating an image that looks very specular. When the roughness increased, the term 
![img](http://latex.codecogs.com/svg.latex?L_%7Bl%7D)
dominated and the image looks matte due to Lambertian reflection.
