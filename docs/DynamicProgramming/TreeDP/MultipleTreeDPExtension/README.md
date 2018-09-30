<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>
<script> gitbook.events.bind("page.change", function() { MathJax.Hub.Queue(["Typeset",MathJax.Hub]); } </script>

# Multiple Tree DP Extension - 多叉树动规扩展

--------

#### 问题

与&lt;Binary Tree DP&gt;类似，对于拥有$$ n $$个节点的多叉树，其节点下标范围为$$ [0,n) $$，节点$$ i $$的权值为$$ v_i $$（$$ v_i \gt 0 $$），整个多叉树的权值为所有节点的权值之和。现在要求只保留$$ m $$个节点（$$ 0 \lt m \lt n $$），剪裁掉$$ n-m $$个节点，要求剩余部分仍然是一个多叉树，而不能是多个树。

对于拥有$$ n $$个节点的多叉树，求出保留$$ m $$个节点的多叉树的最大权值。

#### 解法

与&lt;Binary Tree DP&gt;思路类似，仍然设$$ f(i,j) $$表示以节点$$ i $$为根节点的树上，保留$$ j $$个节点（包括节点$$ i $$自己）的最大权值。其转移方程如下：

$$
f(i,j) =
\begin{cases}
v_i                                         &   (initialize)i,j \in [0,n),i = j \\
max⁡\{ \sum_{1}^{j} f(child_j,k_j )+v_i \}  &   i,j,k \in [0,n), i \neq j, \sum_{1}^{j} k_j = m-1
\end{cases}
$$

$$ (1) $$节点数量为$$ 1 $$的二叉树，其最大权值即为节点自己的权值，即$$ f(i,i) = v_i $$；

$$ (2) $$对于以$$ i $$为根节点的多叉树，假设它拥有$$ j $$个子树，每个子树的根节点分别为$$ child_j $$。子树$$ j $$保留$$ k_j $$个节点，那么所有子树的节点之和即为$$ \sum_{1}^{j} k_j = m-1 $$（加上根节点$$ i $$自己一共$$ m $$个节点）。因此在所有可能中选取最大的权值之和即可；

最终在$$ f(i,m) $$中选择权值最大的作为最终的最大权值（其中$$ i \in [0,n) $$）。该算法的时间复杂度是$$ O(n^2) $$。

--------

#### 源码

[MultipleTreeDPExtension.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MultipleTreeDPExtension.h)

[MultipleTreeDPExtension.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MultipleTreeDPExtension.cpp)

[import, lang:"c_cpp"](../../../../src/DynamicProgramming/TreeDP/MultipleTreeDPExtension.h)

[import, lang:"c_cpp"](../../../../src/DynamicProgramming/TreeDP/MultipleTreeDPExtension.cpp)

#### 测试

[MultipleTreeDPExtensionTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MultipleTreeDPExtensionTest.cpp)

[import, lang:"c_cpp"](../../../../src/DynamicProgramming/TreeDP/MultipleTreeDPExtensionTest.cpp)
