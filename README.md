# Sensor de Luz Analógico – Vasloth (V1)

Sensor de luz analógico desarrollado por **Vasloth Hardware**, diseñado para detectar niveles de iluminación de forma estable y confiable en entornos reales.

A diferencia de módulos de laboratorio o placas abiertas, este sensor prioriza la robustez mecánica, la estabilidad de lectura y la facilidad de integración en proyectos reales de automatización y sistemas embebidos.

---

## Características principales

- Sensor de luz **analógico** basado en LDR  
- Salida analógica estable y de bajo ruido  
- Encapsulado sellado para mayor protección ambiental  
- Compatible con microcontroladores (ESP32, Arduino, etc.)  
- Diseño orientado a uso real, no solo laboratorio  

---

## Alimentación y señal

- **Tensión de alimentación:** 3.3 V (compatible con 5 V según el sistema de lectura)  
- **Salida:** señal analógica proporcional a la intensidad lumínica  
- **Consumo:** muy bajo  

---

## Conexión básica

| Cable | Función |
|------|--------|
| Rojo | VCC |
| Negro | GND |
| Amarillo | Señal analógica |

Se recomienda utilizar pines ADC estables (por ejemplo ADC1 en ESP32) para evitar interferencias.

---

## Funcionamiento

El sensor utiliza un divisor resistivo con un elemento LDR cuya resistencia varía según la luz incidente.  
La señal obtenida es procesada por software para mejorar la estabilidad y reducir el ruido, permitiendo lecturas confiables incluso ante cambios graduales o condiciones variables de iluminación.

---

## Aplicaciones típicas

- Detección de presencia de luz  
- Automatización de iluminación  
- Monitoreo ambiental básico  
- Sistemas embebidos  
- Proyectos educativos e industriales de baja y media exigencia  

---

## Estado del producto

- **Versión:** V1.0  
- **Estado:** Validado  
- **Tipo:** Producción corta / fabricación bajo demanda  

---

## Fabricación

Fabricado en Argentina por **Vasloth Hardware**.

---

## Nota

Este sensor no está diseñado como luxómetro de precisión, sino como un dispositivo robusto y confiable para detección y monitoreo de niveles de iluminación en entornos reales.
