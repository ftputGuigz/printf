# PRINTF 🐋

Ne copiez pas, comprenez et refaites. 🔥 

Sujet conséquent, mais pas trop dur techniquement.\
step by step et organisation et ça passe. 

## mes étapes

1) coder printf pour les opérateurs de conversions sans flags.
2) implémenter les flags pour chaque conversion. \
perso, j'utilise beaucoup (trop) de mallocs mais le résultat est clean notamment au niveau des valeurs de retour. \
je précise que certains flags et opérateurs de conversions sont utilisables pour plusieurs conversions.

## mes conseils

- step by step avancez doucement, 1 conversion à la fois puis 1 flag à la fois. 
- normez en temps réel, testez immédiatement ce que vous implémentez (vos itoas, vos parseurs, vérifiez que votre structure se remplie convenablement, etc...)
Développez - TESTEZ - implémentez 
- Dégommez ☠️ votre printf avec le test de [42-TESTER de Mazoize](https://github.com/Mazoise/42TESTERS-PRINTF) et les [PFT de gavinfielder](https://github.com/gavinfielder/pft) et [PFT-2019 de cclaude42](https://github.com/cclaude42/PFT_2019)

## compte-rendu

- validé avec un tout petit point de bonus très simple à mettre en place.
- Discussion houleuse avec mon dernier correcteur qui a complètement raison : mes mallocs sont mal protégés. Mais pour créer une segfault il fallait modifier mon code donc c'est passé. \
J'ai eu bien chaud, ça n'arrivera plus donc : 

PROTECT YOUR MALLOCS AT ALL COST.

![Capture d’écran 2020-12-28 à 13 33 00](https://user-images.githubusercontent.com/74666017/103216276-f5af9d80-4915-11eb-9c7d-017e90c7b50b.png)
