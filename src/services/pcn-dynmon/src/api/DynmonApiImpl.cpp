/**
 * dynmon API generated from dynmon.yang
 *
 * NOTE: This file is auto generated by polycube-codegen
 * https://github.com/polycube-network/polycube-codegen
 */

/* Do not edit this file manually */

#include "DynmonApiImpl.h"

namespace polycube {
namespace service {
namespace api {

using namespace polycube::service::model;

namespace DynmonApiImpl {
namespace {
std::unordered_map<std::string, std::shared_ptr<Dynmon>> cubes;
std::mutex cubes_mutex;

std::shared_ptr<Dynmon> get_cube(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  auto iter = cubes.find(name);
  if (iter == cubes.end()) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }

  return iter->second;
}

}  // namespace

void create_dynmon_by_id(const std::string &name,
                         const DynmonJsonObject &jsonObject) {
  {
    // check if name is valid before creating it
    std::lock_guard<std::mutex> guard(cubes_mutex);
    if (cubes.count(name) != 0) {
      throw std::runtime_error("There is already a cube with name " + name);
    }
  }
  auto ptr = std::make_shared<Dynmon>(name, jsonObject);
  std::unordered_map<std::string, std::shared_ptr<Dynmon>>::iterator iter;
  bool inserted;

  std::lock_guard<std::mutex> guard(cubes_mutex);
  std::tie(iter, inserted) = cubes.emplace(name, std::move(ptr));

  if (!inserted) {
    throw std::runtime_error("There is already a cube with name " + name);
  }
}

void replace_dynmon_by_id(const std::string &name,
                          const DynmonJsonObject &bridge) {
  throw std::runtime_error("Method not supported!");
}

void delete_dynmon_by_id(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  if (cubes.count(name) == 0) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }
  cubes.erase(name);
}

std::vector<DynmonJsonObject> read_dynmon_list_by_id() {
  std::vector<DynmonJsonObject> jsonObject_vect;
  for (auto &i : cubes) {
    auto m = get_cube(i.first);
    jsonObject_vect.push_back(m->toJsonObject());
  }
  return jsonObject_vect;
}

std::vector<nlohmann::fifo_map<std::string, std::string>>
read_dynmon_list_by_id_get_list() {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  for (auto &x : cubes) {
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = x.first;
    r.push_back(std::move(m));
  }
  return r;
}

/**
 * @brief   Create dataplane by ID
 *
 * Create operation of resource: dataplane*
 *
 * @param[in] name ID of name
 * @param[in] value dataplanebody object
 *
 * Responses:
 *
 */
void create_dynmon_dataplane_by_id(const std::string &name,
                                   const DataplaneJsonObject &value) {
  auto dynmon = get_cube(name);

  return dynmon->addDataplane(value);
}

/**
 * @brief   Delete dataplane by ID
 *
 * Delete operation of resource: dataplane*
 *
 * @param[in] name ID of name
 *
 * Responses:
 *
 */
void delete_dynmon_dataplane_by_id(const std::string &name) {
  auto dynmon = get_cube(name);

  return dynmon->delDataplane();
}

/**
 * @brief   Read dynmon by ID
 *
 * Read operation of resource: dynmon*
 *
 * @param[in] name ID of name
 *
 * Responses:
 * DynmonJsonObject
 */
DynmonJsonObject read_dynmon_by_id(const std::string &name) {
  return get_cube(name)->toJsonObject();
}

/**
 * @brief   Read dataplane by ID
 *
 * Read operation of resource: dataplane*
 *
 * @param[in] name ID of name
 *
 * Responses:
 * DataplaneJsonObject
 */
DataplaneJsonObject read_dynmon_dataplane_by_id(const std::string &name) {
  auto dynmon = get_cube(name);
  return dynmon->getDataplane()->toJsonObject();
}

/**
 * @brief   Read code by ID
 *
 * Read operation of resource: code*
 *
 * @param[in] name ID of name
 *
 * Responses:
 * std::string
 */
std::string read_dynmon_dataplane_code_by_id(const std::string &name) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  return dataplane->getCode();
}

/**
 * @brief   Read metrics by ID
 *
 * Read operation of resource: metrics*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * DataplaneMetricsJsonObject
 */
DataplaneMetricsJsonObject read_dynmon_dataplane_metrics_by_id(
    const std::string &name, const std::string &metricsName) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  return dataplane->getMetrics(metricsName)->toJsonObject();
}

/**
 * @brief   Read metrics by ID
 *
 * Read operation of resource: metrics*
 *
 * @param[in] name ID of name
 *
 * Responses:
 * std::vector<DataplaneMetricsJsonObject>
 */
std::vector<DataplaneMetricsJsonObject>
read_dynmon_dataplane_metrics_list_by_id(const std::string &name) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  auto &&metrics = dataplane->getMetricsList();
  std::vector<DataplaneMetricsJsonObject> m;
  for (auto &i : metrics)
    m.push_back(i->toJsonObject());
  return m;
}

/**
 * @brief   Read map-name by ID
 *
 * Read operation of resource: map-name*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * std::string
 */
std::string read_dynmon_dataplane_metrics_map_name_by_id(
    const std::string &name, const std::string &metricsName) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  auto metrics = dataplane->getMetrics(metricsName);
  return metrics->getMapName();
}

/**
 * @brief   Read open-metrics-metadata by ID
 *
 * Read operation of resource: open-metrics-metadata*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * DataplaneMetricsOpenMetricsMetadataJsonObject
 */
DataplaneMetricsOpenMetricsMetadataJsonObject
read_dynmon_dataplane_metrics_open_metrics_metadata_by_id(
    const std::string &name, const std::string &metricsName) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  auto metrics = dataplane->getMetrics(metricsName);
  return metrics->getOpenMetricsMetadata()->toJsonObject();
}

/**
 * @brief   Read help by ID
 *
 * Read operation of resource: help*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * std::string
 */
std::string read_dynmon_dataplane_metrics_open_metrics_metadata_help_by_id(
    const std::string &name, const std::string &metricsName) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  auto metrics = dataplane->getMetrics(metricsName);
  auto openMetricsMetadata = metrics->getOpenMetricsMetadata();
  return openMetricsMetadata->getHelp();
}

/**
 * @brief   Read labels by ID
 *
 * Read operation of resource: labels*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 * @param[in] labelsName ID of labels_name
 *
 * Responses:
 * DataplaneMetricsOpenMetricsMetadataLabelsJsonObject
 */
DataplaneMetricsOpenMetricsMetadataLabelsJsonObject
read_dynmon_dataplane_metrics_open_metrics_metadata_labels_by_id(
    const std::string &name, const std::string &metricsName,
    const std::string &labelsName) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  auto metrics = dataplane->getMetrics(metricsName);
  auto openMetricsMetadata = metrics->getOpenMetricsMetadata();
  return openMetricsMetadata->getLabels(labelsName)->toJsonObject();
}

/**
 * @brief   Read labels by ID
 *
 * Read operation of resource: labels*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * std::vector<DataplaneMetricsOpenMetricsMetadataLabelsJsonObject>
 */
std::vector<DataplaneMetricsOpenMetricsMetadataLabelsJsonObject>
read_dynmon_dataplane_metrics_open_metrics_metadata_labels_list_by_id(
    const std::string &name, const std::string &metricsName) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  auto metrics = dataplane->getMetrics(metricsName);
  auto openMetricsMetadata = metrics->getOpenMetricsMetadata();
  auto &&labels = openMetricsMetadata->getLabelsList();
  std::vector<DataplaneMetricsOpenMetricsMetadataLabelsJsonObject> m;
  for (auto &i : labels)
    m.push_back(i->toJsonObject());
  return m;
}

/**
 * @brief   Read value by ID
 *
 * Read operation of resource: value*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 * @param[in] labelsName ID of labels_name
 *
 * Responses:
 * std::string
 */
std::string
read_dynmon_dataplane_metrics_open_metrics_metadata_labels_value_by_id(
    const std::string &name, const std::string &metricsName,
    const std::string &labelsName) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  auto metrics = dataplane->getMetrics(metricsName);
  auto openMetricsMetadata = metrics->getOpenMetricsMetadata();
  auto labels = openMetricsMetadata->getLabels(labelsName);
  return labels->getValue();
}

/**
 * @brief   Read type by ID
 *
 * Read operation of resource: type*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * DataplaneMetricsOpenMetricsMetadataTypeEnum
 */
DataplaneMetricsOpenMetricsMetadataTypeEnum
read_dynmon_dataplane_metrics_open_metrics_metadata_type_by_id(
    const std::string &name, const std::string &metricsName) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  auto metrics = dataplane->getMetrics(metricsName);
  auto openMetricsMetadata = metrics->getOpenMetricsMetadata();
  return openMetricsMetadata->getType();
}

/**
 * @brief   Read name by ID
 *
 * Read operation of resource: name*
 *
 * @param[in] name ID of name
 *
 * Responses:
 * std::string
 */
std::string read_dynmon_dataplane_name_by_id(const std::string &name) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();
  return dataplane->getName();
}

/**
 * @brief   Read metrics by ID
 *
 * Read operation of resource: metrics*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * MetricsJsonObject
 */
MetricsJsonObject read_dynmon_metrics_by_id(const std::string &name,
                                            const std::string &metricsName) {
  auto dynmon = get_cube(name);
  return dynmon->getMetrics(metricsName)->toJsonObject();
}

/**
 * @brief   Read metrics by ID
 *
 * Read operation of resource: metrics*
 *
 * @param[in] name ID of name
 *
 * Responses:
 * std::vector<MetricsJsonObject>
 */
std::vector<MetricsJsonObject> read_dynmon_metrics_list_by_id(
    const std::string &name) {
  auto dynmon = get_cube(name);
  auto &&metrics = dynmon->getMetricsList();
  std::vector<MetricsJsonObject> m;
  for (auto &i : metrics)
    m.push_back(i->toJsonObject());
  return m;
}

/**
 * @brief   Read timestamp by ID
 *
 * Read operation of resource: timestamp*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * int64_t
 */
int64_t read_dynmon_metrics_timestamp_by_id(const std::string &name,
                                            const std::string &metricsName) {
  auto dynmon = get_cube(name);
  auto metrics = dynmon->getMetrics(metricsName);
  return metrics->getTimestamp();
}

/**
 * @brief   Read value by ID
 *
 * Read operation of resource: value*
 *
 * @param[in] name ID of name
 * @param[in] metricsName ID of metrics_name
 *
 * Responses:
 * std::string
 */
std::string read_dynmon_metrics_value_by_id(const std::string &name,
                                            const std::string &metricsName) {
  auto dynmon = get_cube(name);
  auto metrics = dynmon->getMetrics(metricsName);
  return metrics->getValue();
}

/**
 * @brief   Read open-metrics by ID
 *
 * Read operation of resource: open-metrics*
 *
 * @param[in] name ID of name
 *
 * Responses:
 * std::string
 */
std::string read_dynmon_open_metrics_by_id(const std::string &name) {
  auto dynmon = get_cube(name);
  return dynmon->getOpenMetrics();
}

/**
 * @brief   Replace dataplane by ID
 *
 * Replace operation of resource: dataplane*
 *
 * @param[in] name ID of name
 * @param[in] value dataplanebody object
 *
 * Responses:
 *
 */
void replace_dynmon_dataplane_by_id(const std::string &name,
                                    const DataplaneJsonObject &value) {
  auto dynmon = get_cube(name);

  return dynmon->replaceDataplane(value);
}

/**
 * @brief   Update dynmon by ID
 *
 * Update operation of resource: dynmon*
 *
 * @param[in] name ID of name
 * @param[in] value dynmonbody object
 *
 * Responses:
 *
 */
void update_dynmon_by_id(const std::string &name,
                         const DynmonJsonObject &value) {
  auto dynmon = get_cube(name);

  return dynmon->update(value);
}

/**
 * @brief   Update dataplane by ID
 *
 * Update operation of resource: dataplane*
 *
 * @param[in] name ID of name
 * @param[in] value dataplanebody object
 *
 * Responses:
 *
 */
void update_dynmon_dataplane_by_id(const std::string &name,
                                   const DataplaneJsonObject &value) {
  auto dynmon = get_cube(name);
  auto dataplane = dynmon->getDataplane();

  return dataplane->update(value);
}

/**
 * @brief   Update dynmon by ID
 *
 * Update operation of resource: dynmon*
 *
 * @param[in] value dynmonbody object
 *
 * Responses:
 *
 */
void update_dynmon_list_by_id(const std::vector<DynmonJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/*
 * help related
 */

std::vector<nlohmann::fifo_map<std::string, std::string>>
read_dynmon_dataplane_metrics_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&dynmon = get_cube(name);
  auto &&dataplane = dynmon->getDataplane();

  auto &&metrics = dataplane->getMetricsList();
  for (auto &i : metrics) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["name"] = i->getName();

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>>
read_dynmon_dataplane_metrics_open_metrics_metadata_labels_list_by_id_get_list(
    const std::string &name, const std::string &metricsName) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&dynmon = get_cube(name);
  auto &&dataplane = dynmon->getDataplane();
  auto &&metrics = dataplane->getMetrics(metricsName);
  auto &&openMetricsMetadata = metrics->getOpenMetricsMetadata();

  auto &&labels = openMetricsMetadata->getLabelsList();
  for (auto &i : labels) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["name"] = i->getName();

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>>
read_dynmon_metrics_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&dynmon = get_cube(name);

  auto &&metrics = dynmon->getMetricsList();
  for (auto &i : metrics) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["name"] = i->getName();

    r.push_back(keys);
  }
  return r;
}

}  // namespace DynmonApiImpl

}  // namespace api
}  // namespace service
}  // namespace polycube
