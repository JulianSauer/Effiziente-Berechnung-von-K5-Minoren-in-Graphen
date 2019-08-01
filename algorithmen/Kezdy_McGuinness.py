find_k5(g):
  if u = find_1_separator(g) != null:
    for component in augmented_components(g, (u)):
      if k5 = find_k5(a) != null:
        return k5
    return null
  if (u, v) = find_2_separator(g) != null:
    for component in augmented_components(g, (u, v)):
      if k5 = find_k5(a) != null:
        return k5
    return null

  homeomorph = boyer_myrvold(g)
  if homeomorph.is_planar():
    return null
  if homeomorph.is_k5:
    return homeomorph
  if homeomorph.is_k33:
    if is_isomorphic_to_w(homeomorph):
      return null

    ((a, b, c), (x, y, z)) = homeomorph
    if component_count(g - (a, b, c)) >= 3:
      for component in augmented_components(g, (a, b, c)):
        if k5 = find_k5(a) != null:
          return k5
      return null
    if component_count(g - (x, y, z)) >= 3:
      for component in augmented_components(g, (x, y, z)):
        if k5 = find_k5(a) != null:
          return k5
      return null

    return construct_k5_from_k33(g, homeomorph)
