# -*- coding: utf-8 -*-
import KBEngine
from KBEDebug import *


class FirstEntity(KBEngine.Proxy):
    """
    第一个实体的base部分的实现
    """

    def __init__(self):
        KBEngine.Entity.__init__(self)
