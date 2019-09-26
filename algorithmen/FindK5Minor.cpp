int FindK5::getWagnerStructure(Graph &input, int k5Limit) {
  Graph minor;
  WagnerStructure structure;
  WagnerMinor m(input, minor, structure);

  int foundK5s = 0;
  while (m.getUntypedComponentCount() > 0) {

    BoyerMyrvold boyerMyrvold;
    SList<KuratowskiWrapper> kuratowskiSubdivisions;
    if (boyerMyrvold.planarEmbed(*m.minor, kuratowskiSubdivisions, 2)) {
      m.specifyNodes(m.minor->nodes, WagnerStructure::NodeType::Planar);
      continue;
    }

    KuratowskiWrapper kuratowskiSubdivision
                      = kuratowskiSubdivisions.popFrontRet();

    if (kuratowskiSubdivision.isK5()) {
      m.specifyNodes(kuratowskiSubdivision.edgeList,
                     WagnerStructure::NodeType::K5);
      foundK5s++;

    } else if (kuratowskiSubdivision.isK33()) {

      if (m.isIsomorphicToW(*m.minor, kuratowskiSubdivision.edgeList)) {
        m.specifyNodes(kuratowskiSubdivision.edgeList,
                       WagnerStructure::NodeType::W);

      } else if (m.split(kuratowskiSubdivision, *m.minor)) {
        continue;

      } else {
        m.specifyNodes(kuratowskiSubdivision.edgeList,
                       WagnerStructure::NodeType::K5);
        foundK5s++;
      }
    }

    if (k5Limit > 0 && foundK5s >= k5Limit)
      return foundK5s;
  }

  return foundK5s;
}
