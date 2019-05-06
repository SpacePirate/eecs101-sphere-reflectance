Generating images of a sphere under orthographic projection using a reflectance model.

The surface of the object was given by the equation\
![img](http://latex.codecogs.com/svg.latex?z%28x%2Cy%29%3Dz_0%2B%5Csqrt%7Br%5E2-%28x%5E2%2By%5E2%29%7D)
The vector components of the normal vector to that sphere was given by the gradient vector such that,\
\[ \frac{dz}{dx} = \frac{-x}{\sqrt{r^2 - (x^2 + y^2)}}\]\
\[ \frac{dz}{dy} = \frac{-y}{\sqrt{r^2 - (x^2 + y^2)}}\]\
\[ \frac{dz}{dz} = 1\]\
The normal vector was normalized to obtain the unit normal vector,\
\[\hat{N} =  {\frac{-x}{r}\vec{i} + \frac{-y}{r}\vec{j} + \frac{\sqrt{r^2 - (x^2 + y^2)}}{r}\vec{k}}\]\
The camera was fixed at the location given by the vector $\hat{V}=\{0,0,1\}$. The light source was varied at the location given by the vector $\hat{S}$. The object had a Lambertian surface profile and the scene radiance was given by the equation,\
\[ L = aL_l + (1-a)L_s \]\
\[ L_l = cos(\theta) \]\
\[ L_s = \exp\{-(\frac{\alpha}{m})^2\} \]\
where $L_l$ was the scene radiance due to the Lambertian refection and $L_s$ was the scene radiance due to the specular reflection. The angle $\theta$ was given by the angle between the vectors $\hat{S}$ and $\hat{N}$ and the angle $\alpha$ was given by the angle between the vectors $\hat{S}$ and $\hat{H}$. The unit angular bisector vector $\hat{H}$ was given by,\
\[ \hat{H} = \frac{\hat{V} + \hat{S}}{|\hat{V} + \hat{S}|} \]\
The parameters r, a, and m, radius of sphere, radiance constant, and material surface roughness, respectively, were varied to observe their effects.\
[Figure 1](https://imgur.com/eUoBpE7.jpg)
<figure class="image">
  <img src="{{ https://imgur.com/eUoBpE7.jpg }}" alt="{{Figure 1. r = 50, a = 0.5, m = 1}}">
  <figcaption>{{ Figure 1. r = 50, a = 0.5, m = 1 }}</figcaption>
</figure>

\textit{Figure 1} displays the orthogonal projection of the object when the parameters were set to "default". Here, the light source positioned at the same location as the camera.\

\begin{figure}[H]
    \fbox{\includegraphics[width=4in]{image_b}} r = 50, a = 0.5, m = 1$}
\end{figure}

\textit{Figure 2} displays the image of the object when the light source was moved away from the default location to positive quadrant of $xy-$plane. The light source points to the object from a $45$ degree angle.
}\[\]

\begin{figure}
    \fbox{\includegraphics[width=4in]{image_c}}
    \caption{$\hat{S} = \{1,0,0\}, r = 50, a = 0.5, m = 1$}
\end{figure}

\textit{Figure 3} displays the image of the object when the light source was again moved to the $x-$axis. Therefore, the light was shined from the right side of the sphere.

\begin{figure}[H]
    \centering
    \fbox{\includegraphics[width=4in]{image_d}}
    \caption{$\hat{S} = \{0,0,1\}, r = 10, a = 0.5, m = 1$}
    \label{image_d}
\end{figure}

\begin{figure}[H]
    \centering
    \fbox{\includegraphics[width=4in]{image_e}}
    \caption{$\hat{S} = \{0,0,1\}, r = 100, a = 0.5, m = 1$}
    \label{image_e}
\end{figure}

\textit{Figure 4} and \textit{Figure 5} displays the image of the object when the radius of the object was decreased and increased, respectively. Therefore, the image of the sphere became smaller and bigger, respectively.\

\begin{figure}[H]
    \centering
    \fbox{\includegraphics[width=4in]{image_f}}
    \caption{$\hat{S} = \{0,0,1\}, r = 50, a = 0.1, m = 1$}
    \label{image_f}
\end{figure}

\begin{figure}[H]
    \centering
    \fbox{\includegraphics[width=4in]{image_g}}
    \caption{$\hat{S} = \{0,0,1\}, r = 50, a = 1, m = 1$}
    \label{image_g}
\end{figure}

\textit{Figure 6} and \textit{Figure 7} displays the image of the object when the Lambertian scene radiance constant, a, was changed. As the constant, a, increased, the gradation of the light became more even. The surface reflected light more evenly as the constant increased and appeared more matte.\

\begin{figure}[H]
    \centering
    \fbox{\includegraphics[width=4in]{image_h}}
    \caption{$\hat{S} = \{0,0,1\}, r = 50, a = 0.5, m = 0.1$}
    \label{image_h}
\end{figure}

\begin{figure}[H]
    \centering
    \fbox{\includegraphics[width=4in]{image_i}}
    \caption{$\hat{S} = \{0,0,1\}, r = 50, a = 0.5, m = 10000$}
    \label{image_i}
\end{figure}

\textit{Figure 8} and \textit{Figure 9} displays the image of the object when the material roughness was changed. As roughness increased, the reflectance became less matte. When the roughness was small, the term $L_s$ dominated in the scene radiance, therefore, creating an image that looks very specular. When the roughness increased, the term $L_l$ dominated and the image looks matte due to Lambertian reflection.\
