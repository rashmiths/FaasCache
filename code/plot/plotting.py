import matplotlib.pyplot as plt
from results import ttl_cache_result, gdsp_cache_result, lru_cache_result, reuse_dist
from results import ttl_coldstart_result, gdsp_coldstart_result, lru_coldstart_result

# Cache sizes
X = [20,40,60,80,100,120]
  

  
# Plotting both the curves simultaneously
plt.plot(X, reuse_dist, color='r', label='Reuse Dist')
plt.plot(X, gdsp_cache_result, color='g', label='GreedyDual')
plt.plot(X, ttl_cache_result, color='b', label='TTL')
plt.plot(X, lru_cache_result, color='y', label='LRU')
  
# Naming the x-axis, y-axis and the whole graph
plt.xlabel("Cache Size")
plt.ylabel("Hit Ratio")
plt.title("Static Provisioning of ideal server size")
  
# Adding legend, which helps us recognize the curve according to it's color
plt.legend()
  
# To load the display window
plt.show()
  
  
# Plotting both the curves simultaneously
plt.plot(X, gdsp_coldstart_result, color='g', label='GreedyDual')
plt.plot(X, ttl_coldstart_result, color='b', label='TTL')
plt.plot(X, lru_coldstart_result, color='y', label='LRU')
  
# Naming the x-axis, y-axis and the whole graph
plt.xlabel("Cache Size")
plt.ylabel("% Cold starts")
plt.title("Fraction of cold starts reduces with GreedyDual")
  
# Adding legend, which helps us recognize the curve according to it's color
plt.legend()
  
# To load the display window
plt.show()