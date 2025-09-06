# 🚁 Drone Delivery Routing System (Lagos)

A professional project implementing a drone delivery routing system within Lagos, Nigeria.  
It uses the **Floyd–Warshall algorithm** for all-pairs shortest paths, and a **Minimum Spanning Tree (MST)** to visualize an efficient backbone delivery network.  
Includes a **C++ implementation** of the core algorithm and an **interactive web-based GUI** for route visualization.  


## 📝 Project Overview
This project simulates a **drone delivery system** within Lagos, Nigeria, connecting locations such as **University of Lagos, Surulere, Akoka, Bariga, Alagomeji, Jibowu, Yaba, Ojuelegba, and Gbagada**.  

It demonstrates how **graph algorithms** can solve **real-world logistics and smart city problems** like:
- Finding shortest paths** between delivery points  
- Computing the **all-pairs shortest-path matrix** for flexible routing  
- Designing a **minimum spanning tree (MST)** to minimize backbone delivery costs  
- Providing an **interactive GUI** for users to query and visualize routes  

---

## ✨ Features
- **Floyd–Warshall Algorithm (C++ & JS)**  
  Computes all-pairs shortest paths with path reconstruction.  

- **MST Visualization**  
  Backbone network overlay using Prim’s algorithm.  

- **Interactive Web GUI**  
  - Responsive SVG map  
  - Select source & destination from dropdowns (black-text for clarity)  
  - Highlights shortest route and displays distance  
  - Exports route JSON (drone-ready input)  

- **Modular Design**  
  Easily extendable with:  
  - GPS coordinates  
  - Drone battery/time constraints  
  - Real-world no-fly zones  

---

## 🛠 Tech Stack
- **Core Algorithm:** C++17 (Floyd–Warshall with path reconstruction)  
- **Web Interface:** HTML5, CSS3, JavaScript (D3.js / SVG rendering)  
- **Visualization:** Responsive graph rendering with MST + routes  
- **Version Control:** Git & GitHub  

---

## 📂 Folder Structure

```bash
drone-delivery-routing-lagos/
├── docs/
│   ├── screenshots/     # Project screenshots
│   └── demo/            # Demo GIFs or videos
├── src/
│   ├── cpp/             # C++ algorithm implementation
│   │   └── floyd.cpp
│   └── web/             # HTML/JS interactive GUI
│       └── index.html
└── README.md            # Project documentation
