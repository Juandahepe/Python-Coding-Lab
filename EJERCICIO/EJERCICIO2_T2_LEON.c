{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 3,
   "id": "b9a234a3",
   "metadata": {},
   "outputs": [],
   "source": [
    "import matplotlib.pyplot as plt\n",
    "import numpy as np\n",
    "import pandas as pd\n",
    "import openpyxl"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "id": "2045bbff",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "inserte la direccion de su archivo (ejemplo:C:/Users/ASUS/Documents/T2.xlsx) :C:/Users/ASUS/Documents/T2.xlsx\n"
     ]
    },
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>h [mm]</th>\n",
       "      <th>b [mm]</th>\n",
       "      <th>t [mm]</th>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>perfil</th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>25</td>\n",
       "      <td>50</td>\n",
       "      <td>5.0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>30</td>\n",
       "      <td>60</td>\n",
       "      <td>5.5</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>35</td>\n",
       "      <td>70</td>\n",
       "      <td>6.0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>40</td>\n",
       "      <td>80</td>\n",
       "      <td>7.0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>5</th>\n",
       "      <td>50</td>\n",
       "      <td>100</td>\n",
       "      <td>8.5</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>6</th>\n",
       "      <td>55</td>\n",
       "      <td>115</td>\n",
       "      <td>9.0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>7</th>\n",
       "      <td>60</td>\n",
       "      <td>120</td>\n",
       "      <td>10.0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>8</th>\n",
       "      <td>70</td>\n",
       "      <td>140</td>\n",
       "      <td>11.5</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>9</th>\n",
       "      <td>80</td>\n",
       "      <td>160</td>\n",
       "      <td>13.0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>10</th>\n",
       "      <td>90</td>\n",
       "      <td>180</td>\n",
       "      <td>15.0</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "        h [mm]  b [mm]  t [mm]\n",
       "perfil                        \n",
       "1           25      50     5.0\n",
       "2           30      60     5.5\n",
       "3           35      70     6.0\n",
       "4           40      80     7.0\n",
       "5           50     100     8.5\n",
       "6           55     115     9.0\n",
       "7           60     120    10.0\n",
       "8           70     140    11.5\n",
       "9           80     160    13.0\n",
       "10          90     180    15.0"
      ]
     },
     "execution_count": 4,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "Mmax = 0.301\n",
    "# direccion archivo utilizada: C:/Users/ASUS/Documents/T2.xlsx\n",
    "archivo = input('inserte la direccion de su archivo (ejemplo:C:/Users/ASUS/Documents/T2.xlsx) :')\n",
    "perfiles = pd.read_excel(archivo, usecols = 'B:E', nrows = 10, skiprows = 3, index_col = 'perfil')\n",
    "perfiles"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "id": "1dac5461",
   "metadata": {},
   "outputs": [],
   "source": [
    "h = perfiles['h [mm]']\n",
    "b = perfiles['b [mm]']\n",
    "t = perfiles['t [mm]']\n",
    "\n",
    "# Área [mm^2]\n",
    "Area_1 = b * t\n",
    "Area_2 = (h-b) * t\n",
    "Area_total = perfiles\n",
    "Area_total['A [mm^2]'] = Area_1 + Area_2\n",
    "\n",
    "# Centroides [mm^4]\n",
    "y_1 = (t/2) + (h-t)\n",
    "y_2 = (h-t)/2\n",
    "Centroide = (y_1 * Area_1 + y_2 * Area_2) / (Area_1 + Area_2)   \n",
    "\n",
    "# Inercias\n",
    "Inercia = perfiles\n",
    "Inercia['Iz [mm^4]'] = (b*(t**3)/12) + Area_1*(y_1 - Centroide) + ((h-t)**3)*t/12 + Area_2*(y_2 - Centroide)\n",
    "\n",
    "#eje neutro\n",
    "Eje_neutro = perfiles\n",
    "Eje_neutro['Eje neutro [mm]'] = Centroide"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "id": "b64dfd2d",
   "metadata": {},
   "outputs": [],
   "source": [
    "# Esfuerzo inferior\n",
    "Esfuerzo_inf = perfiles\n",
    "Esfuerzo_inf['Esfuerzo Inf [MPa]'] = (Mmax*10**6)*Centroide/perfiles['Iz [mm^4]']"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "id": "c4d1566d",
   "metadata": {},
   "outputs": [],
   "source": [
    "# Esfuerzo superior\n",
    "Esfuerzo_sup = perfiles\n",
    "Esfuerzo_sup['Esfuerzo Sup [MPa]'] = (Mmax*10**6)*(h-Centroide)/perfiles['Iz [mm^4]']"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "id": "fd22aafe",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>h [mm]</th>\n",
       "      <th>b [mm]</th>\n",
       "      <th>t [mm]</th>\n",
       "      <th>A [mm^2]</th>\n",
       "      <th>Iz [mm^4]</th>\n",
       "      <th>Eje neutro [mm]</th>\n",
       "      <th>Esfuerzo Inf [MPa]</th>\n",
       "      <th>Esfuerzo Sup [MPa]</th>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>perfil</th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "      <th></th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>25</td>\n",
       "      <td>50</td>\n",
       "      <td>5.0</td>\n",
       "      <td>125.0</td>\n",
       "      <td>3854.166667</td>\n",
       "      <td>35.00</td>\n",
       "      <td>2733.405405</td>\n",
       "      <td>-780.972973</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>30</td>\n",
       "      <td>60</td>\n",
       "      <td>5.5</td>\n",
       "      <td>165.0</td>\n",
       "      <td>7572.182292</td>\n",
       "      <td>42.25</td>\n",
       "      <td>1679.469605</td>\n",
       "      <td>-486.946808</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>35</td>\n",
       "      <td>70</td>\n",
       "      <td>6.0</td>\n",
       "      <td>210.0</td>\n",
       "      <td>13454.500000</td>\n",
       "      <td>49.50</td>\n",
       "      <td>1107.399011</td>\n",
       "      <td>-324.389609</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>40</td>\n",
       "      <td>80</td>\n",
       "      <td>7.0</td>\n",
       "      <td>280.0</td>\n",
       "      <td>23249.916667</td>\n",
       "      <td>56.50</td>\n",
       "      <td>731.464987</td>\n",
       "      <td>-213.613669</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>5</th>\n",
       "      <td>50</td>\n",
       "      <td>100</td>\n",
       "      <td>8.5</td>\n",
       "      <td>425.0</td>\n",
       "      <td>55744.682292</td>\n",
       "      <td>70.75</td>\n",
       "      <td>382.022986</td>\n",
       "      <td>-112.042077</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>6</th>\n",
       "      <td>55</td>\n",
       "      <td>115</td>\n",
       "      <td>9.0</td>\n",
       "      <td>495.0</td>\n",
       "      <td>79988.250000</td>\n",
       "      <td>80.50</td>\n",
       "      <td>302.925742</td>\n",
       "      <td>-95.957844</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>7</th>\n",
       "      <td>60</td>\n",
       "      <td>120</td>\n",
       "      <td>10.0</td>\n",
       "      <td>600.0</td>\n",
       "      <td>114166.666667</td>\n",
       "      <td>85.00</td>\n",
       "      <td>224.102190</td>\n",
       "      <td>-65.912409</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>8</th>\n",
       "      <td>70</td>\n",
       "      <td>140</td>\n",
       "      <td>11.5</td>\n",
       "      <td>805.0</td>\n",
       "      <td>209603.432292</td>\n",
       "      <td>99.25</td>\n",
       "      <td>142.527485</td>\n",
       "      <td>-42.004322</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>9</th>\n",
       "      <td>80</td>\n",
       "      <td>160</td>\n",
       "      <td>13.0</td>\n",
       "      <td>1040.0</td>\n",
       "      <td>355119.916667</td>\n",
       "      <td>113.50</td>\n",
       "      <td>96.202715</td>\n",
       "      <td>-28.394634</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>10</th>\n",
       "      <td>90</td>\n",
       "      <td>180</td>\n",
       "      <td>15.0</td>\n",
       "      <td>1350.0</td>\n",
       "      <td>577968.750000</td>\n",
       "      <td>127.50</td>\n",
       "      <td>66.400649</td>\n",
       "      <td>-19.529603</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "        h [mm]  b [mm]  t [mm]  A [mm^2]      Iz [mm^4]  Eje neutro [mm]  \\\n",
       "perfil                                                                     \n",
       "1           25      50     5.0     125.0    3854.166667            35.00   \n",
       "2           30      60     5.5     165.0    7572.182292            42.25   \n",
       "3           35      70     6.0     210.0   13454.500000            49.50   \n",
       "4           40      80     7.0     280.0   23249.916667            56.50   \n",
       "5           50     100     8.5     425.0   55744.682292            70.75   \n",
       "6           55     115     9.0     495.0   79988.250000            80.50   \n",
       "7           60     120    10.0     600.0  114166.666667            85.00   \n",
       "8           70     140    11.5     805.0  209603.432292            99.25   \n",
       "9           80     160    13.0    1040.0  355119.916667           113.50   \n",
       "10          90     180    15.0    1350.0  577968.750000           127.50   \n",
       "\n",
       "        Esfuerzo Inf [MPa]  Esfuerzo Sup [MPa]  \n",
       "perfil                                          \n",
       "1              2733.405405         -780.972973  \n",
       "2              1679.469605         -486.946808  \n",
       "3              1107.399011         -324.389609  \n",
       "4               731.464987         -213.613669  \n",
       "5               382.022986         -112.042077  \n",
       "6               302.925742          -95.957844  \n",
       "7               224.102190          -65.912409  \n",
       "8               142.527485          -42.004322  \n",
       "9                96.202715          -28.394634  \n",
       "10               66.400649          -19.529603  "
      ]
     },
     "execution_count": 8,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "perfiles"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 9,
   "id": "35c26627",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "El perfil que cumple los requerimientos es el: 7\n"
     ]
    }
   ],
   "source": [
    "Filtro = np.abs(perfiles['Esfuerzo Inf [MPa]']) <= 250\n",
    "perfil_optimo = perfiles.loc[Filtro, 'A [mm^2]']\n",
    "Ind_perfil_optimo = perfiles.loc[Filtro,'A [mm^2]' ].idxmin()\n",
    "print(\"El perfil que cumple los requerimientos es el: \" + str(Ind_perfil_optimo))\n",
    "perfil_optimo_exp = perfiles.loc[[Ind_perfil_optimo], :'A [mm^2]']\n",
    "perfil_optimo_exp2 = perfiles.loc[[Ind_perfil_optimo], 'Esfuerzo Sup [MPa]']\n",
    "perfil_optimo_exp3 = perfiles.loc[[Ind_perfil_optimo], 'Esfuerzo Inf [MPa]']"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 17,
   "id": "a203fddc",
   "metadata": {},
   "outputs": [],
   "source": [
    "from openpyxl import load_workbook\n",
    "with pd.ExcelWriter(archivo, mode='a', engine='openpyxl',if_sheet_exists=\"overlay\") as writer:\n",
    "    book = load_workbook(archivo)\n",
    "    writer.book = book\n",
    "    writer.sheets = dict((ws.title, ws) for ws in book.worksheets)\n",
    "   \n",
    "    perfiles.to_excel(writer, startrow=3, startcol=6, sheet_name='Perfiles')\n",
    "    \n",
    "    perfil_optimo_exp.to_excel(writer, startrow=18, startcol=6, sheet_name=\"Perfiles\", index=None)\n",
    "    perfil_optimo_exp2.to_excel(writer, startrow=18, startcol=11, sheet_name='Perfiles', index=None)\n",
    "    perfil_optimo_exp3.to_excel(writer, startrow=18, startcol=10, sheet_name='Perfiles', index=None)    \n",
    "    \n",
    "    "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "9ac4afb1",
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.10.0"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}