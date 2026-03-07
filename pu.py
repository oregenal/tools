PU_MOD = 3
DAMAGE_MOD = 1.75
PU_REDUCTION = 15
DAMAGE_REDUCTION = 0.95

def norm_damage(pu, damage):
    return 0 if pu > damage else damage - pu

def hp_damage(pu, damage):
    real_pu = pu * PU_MOD
    real_damage = DAMAGE_MOD * damage
    return 0 if real_pu > real_damage else real_damage - real_pu

def threshold(PU_MOD, DAMAGE_MOD):
    return (DAMAGE_MOD - 1) / (PU_MOD - 1)
#damage * DAMAGE_MOD - pu * PU_MOD = damage - pu
#pu * PU_MOD - pu = damage * DAMAGE_MOD - damage
#pu * (PU_MOD - 1) = damage * (DAMAGE_MOD - 1)
#pu = damage * (DAMAGE_MOD - 1) / (PU_MOD - 1)
#pu * (3 - 1) = damage * (1.75 - 1)
#2*pu = 0.75*damage
#pu = (0.75*damage)/2
#pu = 0.375*damage

#damage * DAMAGE_REDUCTION - (pu - PU_REDUCTION) = damage - pu
#(pu - PU_REDUCTION) - pu = damage - damage * DAMAGE_REDUCTION
#(pu - PU_REDUCTION) - pu = damage * (1 - DAMAGE_REDUCTION)
def p_damage(pu, damage):
    real_damage = damage * DAMAGE_REDUCTION
    real_pu = pu - PU_REDUCTION
    return real_damage - (0 if real_pu < 0 else real_pu)
